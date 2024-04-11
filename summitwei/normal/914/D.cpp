#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef long double ld;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
int n;
int val[MN];
int q;

int tree[MN*4];
void build(int node, int a, int b){
    if(a == b){
        tree[node] = val[a];
        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1, 1+(a+b)/2, b);
    tree[node] = __gcd(tree[node*2], tree[node*2+1]);
    //cout << "built " << a << " " << b << " " << tree[node] << "\n";
}
void upd(int node, int a, int b, int i, int val){
    if(a > i || b < i) return;
    if(a == b){
        tree[node] = val;
        return;
    }
    upd(node*2, a, (a+b)/2, i, val);
    upd(node*2+1, 1+(a+b)/2, b, i, val);
    tree[node] = __gcd(tree[node*2], tree[node*2+1]);
}
int que(int node, int a, int b, int i, int j, int val){ //first value in range that isn't mult of val
    if(a > j || b < i || j < i) return n+1;

    if(i <= a && b <= j){
        if(tree[node] % val == 0) return n+1;
        //cout << "yeet bad " << a << " " << b << "\n";
        if(a == b) return a;
        int mid = (a+b)/2;
        int q1 = que(node*2, a, mid, i, j, val);
        if(q1 != n+1) return q1;
        return que(node*2+1, mid+1, b, i, j, val);
    }

    int mid = (a+b)/2;
    int q1 = que(node*2, a, mid, i, j, val);
    if(q1 != n+1) return q1;
    return que(node*2+1, mid+1, b, i, j, val);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> val[i];
    }
    build(1, 1, n);

    cin >> q;
    F0R(_, q){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            
            int fs = que(1, 1, n, l, r, x);
            //cout << "fs is " << fs << "\n";
            if(fs == n+1){
                cout << "YES\n";
            } else{
                int sc = que(1, 1, n, fs+1, r, x);
                //cout << "sc is " << sc << "\n";
                if(sc == n+1){
                    cout << "YES\n";
                } else{
                    cout << "NO\n";
                }
            }
        } else{
            int i, y;
            cin >> i >> y;
            upd(1, 1, n, i, y);
        }
    }

    return 0;
}