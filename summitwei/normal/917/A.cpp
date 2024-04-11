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
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 5005
int n; string s;
bool ok[MN][MN];
bool ok2[MN][MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    n = s.length();
    F0R(i, n){
        int cnt = 0;
        FOR(j, i, n-1){
            if(s[j] == ')') --cnt;
            else ++cnt;

            if(j == i){
                ok[i][j] = cnt>=0;
            } else{
                ok[i][j] = (cnt>=0) && (ok[i][j-1]);
            }
        }
    }
    RFOR(i, n-1, 0){
        int cnt = 0;
        RFOR(j, i, 0){
            if(s[j] == '(') --cnt;
            else ++cnt;

            if(j == i){
                ok2[j][i] = cnt>=0;
            } else{
                ok2[j][i] = (cnt>=0) && (ok2[j+1][i]);
            }
        }
    }
    int ans = 0;
    F0R(i, n){
        FOR(j, i, n-1){
            if(ok[i][j] && ok2[i][j] && i%2 != j%2) ++ans;
        }
    }

    cout << ans;
    
    return 0;
}