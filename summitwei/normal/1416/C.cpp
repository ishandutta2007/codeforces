#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPS 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005 //check limits you incompetent ree
int n;
pii a[MN];
int curB = 30;
bool cmp(pii x, pii y){
    int xp2 = x.f&((1<<curB)-1);
    int xp1 = x.f^xp2;
    int yp2 = y.f&((1<<curB)-1);
    int yp1 = y.f^yp2;
    if(xp1 != yp1) return xp1<yp1;
    return x.s < y.s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    FOR(i, 1, n){ cin >> a[i].f; a[i].s = i; }
    ll ninv = 0;
    int res = 0;
    RFOR(i, 30, 0){
        //cout << "doing " << i << "\n";
        curB = i+1;
        sort(a+1, a+n+1, cmp);
        //stable_sort(a+1, a+n+1, cmp);
        //FOR(j, 1, n) cout << a[j] << " ";
        //cout << "\n";

        ll zo = 0, oz = 0;
        ll zcnt = 0, ocnt = 0;
        FOR(j, 1, n){
            if(j != 1 && __builtin_clz(a[j].f^a[j-1].f) < 32-curB){ //OBO?
                //cout << "cut at " << j << "\n";
                zcnt = 0; ocnt = 0;
            }
            if(a[j].f & (1<<i)){
                zo += zcnt;
                ++ocnt;
            } else{
                oz += ocnt;
                ++zcnt;
            }
        }
        //cout << "got " << zo << " " << oz << "\n";
        if(zo<oz){
            ninv += zo;
            res |= (1<<i);
        } else{
            ninv += oz;
        }
    }
    cout << ninv << " " << res << "\n";

    return 0;
}