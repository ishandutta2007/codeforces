#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, q;
ll x[MN];
ll k[MN];
ll pk[MN];
ll pk2[MN];

ll tree[3*MN];
ll lazy[3*MN];
bool toupd[3*MN];

void build(int node, int a, int b){
    if(a == b){
        tree[node] = x[a];
        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1, 1+(a+b)/2, b);

    tree[node] = tree[node*2]+tree[node*2+1];
}

void upd(int node, int a, int b, int i, int j, ll val){
    if(toupd[node]){
        tree[node] = lazy[node]*(b-a+1)+(pk2[b-1]-pk2[a-1]-pk[a-1]*(b-a));//-(pk[b-1]-pk[a-1])*(a-1);
        //cout << "amt from " << a << " to " << b << " with start " << lazy[node] << " is " << tree[node] << "\n";
        if(a != b){
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node]+pk[(a+b)/2]-pk[a-1];
            toupd[node*2] = true;
            toupd[node*2+1] = true;
        }
        lazy[node] = 0;
        toupd[node] = false;
    }

    if(a > j || b < i || b < a) return;
    
    if(i <= a && b <= j){
        ll sv = val+pk[a-1]-pk[i-1];
        tree[node] = sv*(b-a+1)+(pk2[b-1]-pk2[a-1]-pk[a-1]*(b-a));//-(pk[b-1]-pk[a-1])*(a-1);
        //cout << "amt from " << a << " to " << b << " with start " << sv << " is " << tree[node] << "\n";
        if(a != b){
            lazy[node*2] = sv;
            lazy[node*2+1] = sv+pk[(a+b)/2]-pk[a-1];
            toupd[node*2] = true;
            toupd[node*2+1] = true;
        }
        return;
    }

    upd(node*2, a, (a+b)/2, i, j, val);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val);
    tree[node] = tree[node*2]+tree[node*2+1];
}

ll que(int node, int a, int b, int i, int j){
    if(toupd[node]){
        tree[node] = lazy[node]*(b-a+1)+(pk2[b-1]-pk2[a-1]-pk[a-1]*(b-a));//-(pk[b-1]-pk[a-1])*(a-1);
        //cout << "amt from " << a << " to " << b << " with start " << lazy[node] << " is " << tree[node] << "\n";
        if(a != b){
            lazy[node*2] = lazy[node];
            lazy[node*2+1] = lazy[node]+pk[(a+b)/2]-pk[a-1];
            toupd[node*2] = true;
            toupd[node*2+1] = true;
        }
        lazy[node] = 0;
        toupd[node] = false;
    }

    if(a > j || b < i || b < a) return 0;
    
    if(i <= a && b <= j){
        return tree[node];
    }
    
    ll q1 = que(node*2, a, (a+b)/2, i, j);
    ll q2 = que(node*2+1, 1+(a+b)/2, b, i, j);

    return q1+q2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> x[i];
    }
    FOR(i, 1, n-1){
        cin >> k[i];
        pk[i] = pk[i-1]+k[i];
        pk2[i] = pk2[i-1]+pk[i];
        //cout << i << " " << pk[i] << " " << pk2[i] << "\n";
    }

    build(1, 1, n);

    cin >> q;
    F0R(_, q){
        char c;
        cin >> c;
        if(c == '+'){
            int i, x;
            cin >> i >> x;

            ll iv = que(1, 1, n, i, i)+x;

            int l = i; //this is sketchy. how to bs
            int r = n+1;
            while(l+1<r){
                int mid = (l+r)/2;
                
                ll val = que(1, 1, n, mid, mid);
                //int cb = que(1, 1, );
                ll cb = iv+pk[mid-1]-pk[i-1];
                //cout << "at " << mid << ", " << val << " is val and " << cb << " is the result\n";
                if(cb > val){
                    l = mid;
                } else{
                    r = mid;
                }
            }
            //cout << "rb is " << l << "\n";
            upd(1, 1, n, i, l, iv);
        } else{
            int l, r;
            cin >> l >> r;
            cout << que(1, 1, n, l, r) << "\n";
        }
    }

    
    return 0;
}