#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 50, K = 105, INF = (int)1e9;
string sufs[] = {"", "o", "on", "one", "t", "tw", "two"};
int nxt[7][256];
int dp[N][7], tak[N][7];
string str;
int n;

int solve(int idx, int st) {
    if(dp[idx][st] != -1) return dp[idx][st];
    if(idx == n) return 0;
    dp[idx][st] = INF;
    int tk = nxt[st][str[idx]];
    if(tk != 3 && tk != 6) dp[idx][st] = solve(idx + 1, tk), tak[idx][st] = 0;
    int take = solve(idx + 1, st) + 1;
    if(take < dp[idx][st]) dp[idx][st] = take, tak[idx][st] = 1;
    return dp[idx][st];
}
vector<int> pos;

void trace(int idx, int st) {
    if(idx == n) return ;
    if(tak[idx][st]) {
        pos.push_back(idx);
        trace(idx + 1, st);
    }
    else {
        trace(idx + 1, nxt[st][str[idx]]);
    }
}

bool is_suf(string s, string t) {
    int slen = s.length(), tlen = t.length();
    if(slen > tlen) return false;
    return s == t.substr(tlen - slen);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 7; i++) {
        for(char c = 'a'; c <= 'z'; c++) {
            for(int j = 0; j < 7; j++) {
                if(is_suf(sufs[j], sufs[i] + c) && sufs[j].length() > sufs[nxt[i][c]].length())
                    nxt[i][c] = j;
            }
        }
    }
//    int a;
//    char b;
//    while(cin >> a >> b) {
//        cout << nxt[a][b] << endl;
//    }
    int T;
    cin >> T;

    while(T--) {
        pos.clear();
        cin >> str;
        n = str.length();
        for(int i = 0; i <= n + 1; i++) fill(dp[i], dp[i] + 7, -1);
        solve(0, 0);
        trace(0, 0);
        cout << pos.size() << "\n";
        for(int x : pos) cout << x + 1 << " ";
        cout << '\n';

    }
}