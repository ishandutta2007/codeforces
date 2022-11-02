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
#define MD 30
int n; string s; int q;
int ps[MN][MD];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> s >> q;
    n = s.length();
    F0R(i, n){
        F0R(j, 26){
            ps[i+1][j] = ps[i][j];
            if(s[i]-'a' == j) ++ps[i+1][j];
        }
    }
    F0R(_, q){
        int l, r;
        cin >> l >> r;
        int ubniqu = 0;
        int uno = 0;
        F0R(j, 26){
            if(ps[r][j] != ps[l-1][j]){
                ++ubniqu;
                if(ps[r][j]-ps[l-1][j] == 1) ++uno;
            }
        }
        if(l != r && ubniqu == 1){
            cout << "No\n";
        } else{
            if(ubniqu == 2 && s[l-1] == s[r-1]){
                cout << "No\n";
            } else{
                cout << "Yes\n";
            }
        }
    }
 
    return 0;
}