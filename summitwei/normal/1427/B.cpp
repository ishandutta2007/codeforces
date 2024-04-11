#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

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

#define MN 100005 //check limits you incompetent ree
int n, k;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        cin >> n >> k >> s;
        int cnt = 0;
        int csk = -INF;
        vi strk;
        F0R(i, n){
            if(s[i]=='W'){
                if(csk > 0) strk.pb(csk);
                csk = 0;
                ++cnt;
            } else{
                csk++;
            }
        }
        sort(strk.begin(), strk.end());
        int sm = 0, i=0;
        while(i!=strk.size() && sm+strk[i] <= k){ sm+=strk[i]; ++i; }
        int numwin = min(n, k+cnt);
        int numstrk = strk.size()-i;
        cout << max(0, numwin+(numwin-1-numstrk)) << "\n";
    }

    return 0;
}