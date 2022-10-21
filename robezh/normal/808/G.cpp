#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50, INF = (int)1e9;

struct KMP {
    int f[N];
    string t;

    void getnext(){
        int m = t.length();
        f[0] = 0; f[1] = 0;
        for(int i = 1; i < m; i++){
            int j = f[i];
            while(j && t[i] != t[j]) j = f[j];
            f[i+1] = t[i] == t[j] ? j + 1 : 0;
        }
    }
} kmp;

string s, t;

int n, m;
int nxt[N][26];
vector<vector<int> > st;
vector<int> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;
    n = s.length(), m = t.length();
    kmp.t = t;
    kmp.getnext();
    for(int i = 0; i < m; i++) {
        for(int c = 0; c < 26; c++) {
            if(t[i] == (char)(c + 'a')) nxt[i][c] = i+1;
            else nxt[i][c] = nxt[kmp.f[i]][c];
        }
    }
    s = " " + s;
    st.resize(n + 1, vector<int>(m + 1, -1));
    st[0][0] = 0;


    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(st[i-1][j] == -1) continue;
            int cur = j == m ? kmp.f[j] : j;
            char l = s[i] == '?' ? 'a' : s[i];
            char r = s[i] == '?' ? 'z' : s[i];
            for(char c = l; c <= r; c++) {
                int nx = nxt[cur][c - 'a'];
                st[i][nx] = max(st[i][nx], st[i-1][j] + (nx == m));
            }
        }
    }
    int res = 0;
    for(int i = 0; i <= m; i++) res = max(res, st[n][i]);
    cout << res << endl;


}