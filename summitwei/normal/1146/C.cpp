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
vi s1;
vi s2;

int que(){
    if(s1.size() == 0 || s2.size() == 0) return 0;

    cout << s1.size() << " " << s2.size();
    F0R(i, s1.size()){
        cout << " " << s1[i];
    }
    F0R(i, s2.size()){
        cout << " " << s2[i];
    }
    cout << endl;
    cout.flush();
    int res;
    cin >> res;
    if(res == -1) exit(0);
    return res;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int t;
    cin >> t;
    F0R(_, t){
        int n;
        cin >> n;

        int ans = 0;
        F0R(i, 9){
            s1.clear();
            s2.clear();
            FOR(j, 1, n){
                if(j & (1<<i)){
                    s1.pb(j);
                } else{
                    s2.pb(j);
                }
            }

            int res = que();
            ans = max(ans, res);
        }

        cout << "-1 " << ans << endl;
        cout.flush();
    }
    
    return 0;
}