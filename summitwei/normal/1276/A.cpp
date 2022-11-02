#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s secondc
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1500005
int t;
string s;
vi bad;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        cin >> s;
        int ok = -1;
        F0R(i, s.length()-2){
            if(ok >= i) continue;
            if(s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e'){
                bad.pb(i+1);
                ok = i+2;
            } else if(s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o'){
                if(i+4 < s.length()){
                    if(s[i+3] == 'n' && s[i+4] == 'e'){
                        bad.pb(i+2);
                        ok = i+4;
                    } else{
                        bad.pb(i+1);
                        ok = i+2;
                    }
                } else{
                    bad.pb(i+1);
                    ok = i+2;
                }
            }
        }
        cout << bad.size() << "\n";
        F0R(i, bad.size()) cout << bad[i]+1 << " ";
        cout << "\n";

        bad.clear();
    }
    
    return 0;
}