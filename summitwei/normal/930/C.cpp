#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, m;
pii a[MN];
int ps[MN];

int tree[MN*4];
void upd(int node, int a, int b, int i, int j, int val){
    if(a > b || a > j || b < i) return;
 
    if(i <= a && b <= j){
        tree[node] = max(tree[node], val);
        return;
    }
 
    upd(node*2, a, (a+b)/2, i, j, val);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val);
    tree[node] = max(tree[node*2], tree[node*2+1]);
}
int que(int node, int a, int b, int i, int j){
    if(a > b || a > j || b < i) return 0;
 
    if(a >= i && b <= j) return tree[node];
 
    int q1 = que(node*2, a, (a+b)/2, i, j);
    int q2 = que(node*2+1, 1+(a+b)/2, b, i, j);
 
    return max(q1, q2);
}
int frw[MN];
int bck[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, n){
        cin >> a[i].f >> a[i].s;
        ps[a[i].f]++;
        ps[a[i].s+1]--;
    }
    FOR(i, 1, m){
        ps[i] += ps[i-1];
    }
    FOR(i, 1, m){
        ps[i]++;
        //cout << ps[i] << " ";
    }
    //cout << "\n";

    FOR(i, 1, m){
        int amt = que(1, 1, n+1, 1, ps[i]);
        frw[i] = amt+1;
        upd(1, 1, n+1, ps[i], ps[i], amt+1);
    }
    memset(tree, 0, sizeof tree);
    RFOR(i, m, 1){
        int amt = que(1, 1, n+1, 1, ps[i]);
        bck[i] = amt+1;
        upd(1, 1, n+1, ps[i], ps[i], amt+1);
    }

    int ans = 0;
    FOR(i, 1, m){
        //cout << frw[i] << " " << bck[i] << "\n";
        ans = max(ans, frw[i]+bck[i]-1);
    }
    cout << ans << "\n";
    
    return 0;
}