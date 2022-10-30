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
#define MOD 998244353LL
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
int p[MN];
int inv[MN];

ll tree[2][MN*4]; //1s, is
void upd(int node, int a, int b, int i, int j, ll val, int tp){
    if(a > b || a > j || b < i) return;

    if(i <= a && b <= j){
        tree[tp][node] = max(tree[tp][node], val);
        return;
    }

    upd(node*2, a, (a+b)/2, i, j, val, tp);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val, tp);
    tree[tp][node] = tree[tp][node*2]+tree[tp][node*2+1];
}
ll que(int node, int a, int b, int i, int j, int tp){
    if(a > b || a > j || b < i) return 0;
 
    if(a >= i && b <= j) return tree[tp][node];
 
    ll q1 = que(node*2, a, (a+b)/2, i, j, tp);
    ll q2 = que(node*2+1, 1+(a+b)/2, b, i, j, tp);

    return q1+q2;
}

set<int> hmph;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){
        cin >> p[i];
        inv[p[i]] = i;
    }
    ll icnt = 0;
    FOR(i, 1, n){
        int loc = inv[i];
        ll amt = que(1, 1, n, loc+1, n, 0);
        icnt += amt;

        upd(1, 1, n, loc, loc, 1, 0);
        upd(1, 1, n, loc, loc, loc, 1);

        int half = (i+1)/2;
        int l=0, r=n;
        while(l+1<r){
            int mid = (l+r)/2;
            int cnt = que(1, 1, n, 1, mid, 0);

            //cout << mid << " " << cnt << "\n";

            if(cnt >= half){
                r = mid;
            } else{
                l = mid;
            }
        }
        //cout << "median is " << r << "\n";
        ll sm1 = 1LL*(r+r-half+1)*half/2 - que(1, 1, n, 1, r, 1);
        ll sm2 = que(1, 1, n, r+1, n, 1) - 1LL*(r+1+r+i-half)*(i-half)/2;
        //cout << icnt << " " << sm1 << " " << sm2 << " ";
        cout << icnt + sm1 + sm2 << " ";
    }

    return 0;
}