#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
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

#define MN 100005
int t;
int n, k;
string s;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    F0R(_, t){
        memset(a, 0, sizeof a);
        cin >> n >> k >> s;
        F0R(i, n) a[s[i]-'a']++;
        //string res = "";
        bool ok = false;
        //cout << "starting new\n\n";

        F0R(i, 26){
            if(a[i] != 0){
                if(a[i] < k){
                    int cnt = a[i];
                    FOR(j, i+1, 25){
                        cnt += a[j];
                        if(cnt >= k){
                            cout << (char)(j+'a') << "\n";
                            ok = true;
                            break;
                        }
                    }
                    break;
                }
                cout << (char)(i+'a');
                a[i] -= k;
                n -= k;
                break;
            }
        }
        if(ok) continue;

        F0R(i, 26){
            if(a[i] == n){
                //cout << "found perfect\n";
                F0R(_, (a[i]+k-1)/k){
                    cout << (char)(i+'a');
                }
                cout << "\n";
                ok = true;
                break;
            }
        }
        if(!ok){
            //cout << "bruh\n";
            F0R(i, 26) F0R(j, a[i]) cout << (char)(i+'a');
            cout << "\n";
        }
    }
    
    return 0;
}