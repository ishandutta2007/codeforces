#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 100000000000000LL
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
int n;
int a[MN];
ll s[MN];
ll tree[3*MN];
ll lazy[3*MN];

void build(int node, int a, int b){
    if(a == b){
        tree[node] = s[a];
        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1, (a+b)/2+1, b);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}
void upd(int node, int a, int b, int i, int j, ll val){
    if(a > j || b < i || b < a) return;
    
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(i <= a && b <= j){
        tree[node] += val;
        if(a != b){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }

    upd(node*2, a, (a+b)/2, i, j, val);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}
ll que(int node, int a, int b, int i, int j){
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(a > j || b < i || b < a) return INF;

    if(i <= a && b <= j){
        return tree[node];
    }
    
    ll q1 = que(node*2, a, (a+b)/2, i, j);
    ll q2 = que(node*2+1, 1+(a+b)/2, b, i, j);
    return min(q1, q2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> s[i];
    }
    build(1, 1, n);

    FOR(i, 1, n){
        int l = 1, r = n+1;
        while(l+1 < r){
            int mid = (l+r)/2;
            //cout << que(1, 1, n, mid, n) << "\n";
            if(que(1, 1, n, mid, n) == 0){
                l = mid;
            } else{
                r = mid;
            }
        }
        a[l] = i;
        upd(1, 1, n, l, l, INF);
        upd(1, 1, n, l+1, n, -i);
        //FOR(i, 1, 5) cout << tree[i] << " " << lazy[i] << "\n";
    }

    FOR(i, 1, n){
        cout << a[i] << " ";
    }

    return 0;
}