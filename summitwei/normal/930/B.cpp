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

#define MN 5005
#define MM 26
string s;
int n;
int apps[MN];
int app2[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.length();
    s += s;
    int ans = 0;
    F0R(c, 26){
        memset(apps, 0, sizeof apps);
        memset(app2, 0, sizeof app2);
        //cout << "doing " << c << "\n";
        F0R(i, n){
            if(s[i]-'a' != c) continue;
            FOR(j, i+1, i+n-1){
                int ind = j-i;
                int ch = s[j]-'a';
                //cout << "found " << ch << " dist of " << ind << " from " << i << "\n";
                if(apps[ind] & (1<<ch)){
                    app2[ind] &= (1<<26)-1-(1<<ch);
                } else{
                    apps[ind] |= (1<<ch);
                    app2[ind] |= (1<<ch);
                }
            }
        }
        int mx = 0;
        FOR(j, 1, n-1){
            //cout << j << " has " << app2[j] << "\n";
            mx = max(mx, __builtin_popcount(app2[j]));
        }
        //cout << "got max of " << mx << "\n";
        ans += mx;
    }
    cout << fixed << setprecision(8) << (double)ans/n << "\n";
    
    return 0;
}