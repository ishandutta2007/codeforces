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

#define MN 10005 //check limits you incompetent ree
int n;
ll a[MN];
ll res[MN]; //amt needed to carry over
vector<pair<pii, int> > aah;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n;
        ll sm = 0;
        FOR(i, 1, n){
            cin >> a[i];
            sm += a[i];
        }
        if(sm%n != 0){
            cout << "-1\n";
            continue;
        }
        ll tg = sm/n;

        FOR(i, 2, n){
            int tm = i-a[i]%i;
            if(tm==i) tm=0;
            if(tm != 0) aah.pb({{1, i}, tm});
            if(a[i] != 0) aah.pb({{i, 1}, (a[i]+i-1)/i});
        }
        FOR(i, 2, n){
            aah.pb({{1, i}, tg});
        }

        //bool bd = false;
        /*FOR(i, 2, n){
            if(a[i]%i > tg){
                bd = true;
                break;
            }
            if(a[i] >= i){
                aah.pb({{i, 1}, a[i]/i});
                a[1] += (a[i]/i)*i;
                a[i] -= (a[i]/i)*i;
            }
        }*/
        /*if(bd){
            cout << "-1\n";
            aah.clear();
            continue;
        }*/
        /*FOR(i, 2, n){
            if(tg == a[i]) continue;
            aah.pb({{1, i}, tg-a[i]});
            a[1] -= tg-a[i];
            a[i] += tg-a[i];
        }*/
        cout << aah.size() << "\n";
        for(auto u : aah){
            cout << u.f.f << " " << u.f.s << " " << u.s << "\n";
        }
        aah.clear();
    }

    return 0;
}