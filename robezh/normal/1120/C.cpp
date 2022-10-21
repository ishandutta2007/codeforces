#include <bits/stdc++.h>
using namespace std;

const int N = (int)5005, INF = (int)1e9;

int n, a, b;
string str;

struct Zalgo {
    int z[N];

    void getZarr(string str)
    {
        memset(z, 0, sizeof(z));
        int n = str.length();
        for(int i = 1, l = 0, r = 0; i < n; ++i){
            if(i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while(i + z[i] < n && str[z[i]] == str[i + z[i]])
                ++z[i];
            if(i + z[i] - 1 > r)
                l = i,  r = i + z[i] - 1;
        }
    }
}zalgo;

bool good[N][N];
int dp[N];

int main(){
    fill(dp, dp + N, INF);

    cin >> n >> a >> b;
    cin >> str;

    for(int i = 1; i < n; i++) {
        zalgo.getZarr(str.substr(i) + "$" + str.substr(0, i));
        int mx = 0;
        for(int j = n - i + 1; j <= n; j++) mx = max(mx, zalgo.z[j]);
        for(int j = 1; j <= mx; j++) good[i][i+j-1] = true;
    }
    dp[0] = a;
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= i; j++) {
            if(good[j][i]) dp[i] = min(dp[i], dp[j-1] + b);
        }
        dp[i] = min(dp[i-1] + a, dp[i]);
//        cout << i << ": " << dp[i] << endl;
    }
    cout << dp[n-1] << endl;



}