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
#define INF 1000000000LL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 2000005
int q;
string s;
string t;
int p[MN];

int bs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 bruh(seed1);
    bs = 100+bruh()%100;

    cin >> q;
    F0R(_, q){
        cin >> s;
        int n = s.length();
        t.resize(2*n+1);
        F0R(i, n){
            t[i*2] = '#';
            t[i*2+1] = s[i];
        }
        t[n*2] = '#';
        n = 2*n+1;
        //cout << "doing " << t << "\n";
        
        int C = 0, R = -1, rad; 
        for (int i = 0; i < t.length(); ++i) {
            if (i <= R) {
                rad = min(p[2*C-i], R-i); 
            } else {
                rad = 0; 
            }
            // Try to extend
            while (i+rad < t.length() && i-rad >= 0 && t[i-rad] == t[i+rad]) {
                rad++; 
            }
            p[i] = rad-1;
            if (i + rad - 1 > R) {
                C = i; 
                R = i + rad - 1; 
            }
        }

        /*F0R(i, n){
            cout << p[i] << " ";
        }
        cout << "\n";*/

        int mx = 0;
        while(mx*2 < n && t[mx] == t[n-1-mx]) ++mx;

        //cout << "mx is " << mx << "\n";

        int res = 0;
        int loc = 0;
        int o = 0;
        F0R(i, n){
            int len = p[i];
            if(i <= n/2 && i-len <= mx){
                int cl = (i-len)*2+len*2+1;
                //cout << "found1 " << i << " " << cl << "\n";
                if(cl > res){
                    res = cl;
                    loc = i;
                    o = i-len;
                }
            } else if(i >= n/2 && n-1-i-len <= mx){
                int cl = (n-1-i-len)*2+len*2+1;
                //cout << "found2 " << i << " " << cl << "\n";
                if(cl > res){
                    res = cl;
                    loc = i;
                    o = (n-1-i-len);
                }
            }
        }
        //cout << "got " << res << " " << loc << " " << o << "\n";
        int ot = loc-p[loc];
        string ans = t.substr(0, o) + t.substr(ot, p[loc]*2+1) + t.substr(n-o);
        F0R(i, ans.length()){
            if(ans[i] != '#') cout << ans[i];
        }
        cout << "\n";
    }

    return 0;
}