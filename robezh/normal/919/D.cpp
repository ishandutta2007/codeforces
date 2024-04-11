#include <bits/stdc++.h>
using namespace std;

vector<int> V[300005];
int n,m;
string str;
int a, b;
int s[300005];
int dp[300005];

bool check(int v){
    s[v] = -1;
    for(int nxt : V[v]){
        if(s[nxt] == -1) return false;
        if(s[nxt] == 1) continue;
        if(!check(nxt)) return false;
    }
    s[v] = 1;

    return true;
}

int dfs(int v, char c){
    if(dp[v] != -1) return dp[v];

    int res = 0;
    for(int nxt : V[v]){
        res = max(res, dfs(nxt, c));
    }
    if(str[v] == c) res ++;

    return dp[v] = res;


}

int main() {
    fill(s, s+300005, 0);
    scanf("%d%d", &n, &m);
    getchar();
    getline(cin, str);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        a--, b--;
        V[a].push_back(b);
    }
    for(int i = 0; i < n; i++){
        if(s[i] == 0){
            if(!check(i)) return !printf("-1");
        }
    }

    //cout <<"Passed" << endl;
    int fres = 0;
    for(char c = 'a'; c <= 'z'; c++){
        int res = 0;
        fill(dp, dp+n, -1);
        for(int i = 0; i < n; i++){
            if(dp[i] == -1){
                res = max(res, dfs(i,c));
            }
        }
        fres = max(res, fres);
    }
    cout << fres;

}