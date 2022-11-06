#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

char s[sz][55];
vector <int> g[30];
bool vis[30];

void dfs(int u)
{
    queue <int> q;
    q.push(u);
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++) {
            int v=g[u][i];
            int l=strlen(s[v]);
            for(int j=0; j<l; j++) {
                int x=s[v][j]-'a';
                if(!vis[x]) {
                    q.push(x);
                    vis[x]=1;
                }
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%s", s[i]);
        int l=strlen(s[i]);
        for(int j=0; j<l; j++) {
            g[s[i][j]-'a'].push_back(i);
        }
    }

    int ans=0;
    for(int i=0; i<30; i++) {
        if(!vis[i] && g[i].size()) {
            dfs(i);
            ans++;
        }
    }

    cout << ans << endl;
}