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

#define MN 100005
int n, d, m;
vector<ll> a, b;


int main(){
    cin >> n >> d >> m;
    F0R(i, n){
        ll x;
        cin >> x;
        if(x<=m) a.pb(x);
        else b.pb(x);
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    ll mx = -INF;
    ll bsum = 0;
    ll asum = 0;
    F0R(i, min((int)a.size(), n)) asum += a[i];
    int lst = min((int)a.size(), n);
    mx = asum;
    //cout << mx << "\n";
    F0R(i, b.size()){
        bsum += b[i];
        if(i*d+(i+1)>n) break;
        while(i*d+(i+1)+lst>n){
            --lst;
            //cout << "yeeting " << lst << "\n";
            asum -= a[lst];
        }
        //cout << i << " " << asum << " " << bsum << "\n";
        mx = max(mx, asum+bsum);
    }
    cout << mx << "\n";

    return 0;
}