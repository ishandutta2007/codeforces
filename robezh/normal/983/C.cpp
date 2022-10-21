#include <bits/stdc++.h>
using namespace std;

const int N = (int)2005, INF = (int)1e9;

int n, a[N], b[N];
map<string, int> dp[N][10];

int dfs(int i, int lev, string st){
    if(i == n && st == "0000") return 0;
    int &res = dp[i][lev][st];
    string s;
    if(res) return res;
    res = INF;
    for(int j = 1; j <= 9; j++){
        s = st;
        int tim = 0, ni = i;
        for(int k = 0; k < 4; k++) if(s[k] == '0'+j){s[k] = '0'; tim++;}
        for(int k = 0; k < 4; k++) if(s[k] == '0' && a[ni+1] == j){s[k] = (char)('0'+b[ni+1]); ni++; tim++;}
        sort(s.begin(), s.end());
        if(ni != i || s != st) res = min(res, dfs(ni, j, s) + abs(j - lev) + tim);
    }
    return res;

}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    cout << dfs(0, 1, "0000") << endl;
}