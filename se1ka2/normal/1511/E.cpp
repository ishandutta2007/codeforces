#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

string s[300005];
ll p[300005];
ll q[300005];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    ll w = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'o') w++;
        }
    }
    p[0] = 1;
    for(int i = 1; i <= w; i++) p[i] = p[i - 1] * 2 % MOD;
    ll ans = 0;
    vector<vector<int>> r(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        int t = m;
        for(int j = m - 1; j >= 0; j--){
            if(s[i][j] == '*') t = j;
            r[i][j] = t;
        }
    }
    vector<vector<int>> d(n, vector<int>(m));
    for(int j = 0; j < m; j++){
        int t = n;
        for(int i = n - 1; i >= 0; i--){
            if(s[i][j] == '*') t = i;
            d[i][j] = t;
        }
    }
    for(int i = 2; i <= w; i++){
        if(i % 2) q[i] = (q[i - 1] + MOD - p[w - i]) % MOD;
        else q[i] = (q[i - 1] + p[w - i]) % MOD;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = (ans + q[r[i][j] - j] + q[d[i][j] - i]) % MOD;
        }
    }
    cout << ans << endl;
}