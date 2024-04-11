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
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
#define MN 200005
int n;
string s;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> s;
    int dif = 0;
    int ans = 0;
    F0R(i, n){
        if(s[i] == ')'){ --dif; if(dif < 0) ans += 2;}
        if(s[i] == '(') ++dif;
    }
 
    if(dif != 0){
        cout << "-1\n";
    } else{
        cout << ans << "\n";
    }
 
    return 0;
}