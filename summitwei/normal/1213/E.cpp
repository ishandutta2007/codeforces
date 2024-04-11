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
#define INF 0x3f3f3f3f
#define MOD 1000000007
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
string s, t;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> s >> t;
    cout << "YES\n";
    if(t[0] == t[1]) swap(s, t);
    if(s[0] == s[1]){
        if(t[1]-t[0] == 0 || t[1]-t[0] == 1 || t[1]-t[0] == -2){
            F0R(_, n){
                cout << "acb";
            }
        } else{
            F0R(_, n){
                cout << "abc";
            }
        }
    } else{
        char a, b, c;
        b = 3*'b'-s[0]-s[1];
        if(b == t[0]){
            a = t[1]; c = 3*'b'-t[1]-b;
        } else{
            c = t[0]; a = 3*'b'-t[0]-b;
        }
        F0R(_, n){
            cout << a;
        }
        F0R(_, n){
            cout << b;
        }
        F0R(_, n){
            cout << c;
        }
    }

    return 0;
}