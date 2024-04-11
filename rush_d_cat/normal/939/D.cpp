#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100000+10;
int n; char s1[N], s2[N];
int mp[30][30], dis[30][30], par[N], deg[30];

int find(int x) {
    return x == par[x] ? par[x]: par[x] = find(par[x]);
}

vector<int> g[N];
vector< pair<int, int> > ans; 

int main() {
    for (int i = 0; i <= 1000; i ++) par[i] = i;
    
    scanf("%d %s %s", &n, s1+1, s2+1);
    
    for (int i = 1; i <= n; i ++) {
        mp[s1[i]-'a'][s2[i]-'a'] = 1;
        par[ find(s1[i]-'a') ] = find(s2[i]-'a');
    }

    for (int i = 0; i < 26; i ++) {
        g[find(i)].push_back(i);
    }

    for (int i = 0; i < 26; i ++) {
        for (int j = 0; j < 26; j ++) if (mp[i][j]) {
            deg[j] ++;
        }
    }
    for (int i = 0; i < 26; i ++) {
        if (g[i].size() < 2) continue;
        for (int j = 0; j < (int)g[i].size()-1; j ++) {
            ans.push_back(make_pair(g[i][j], g[i][j+1]));
        }
    }

    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i ++) {
        printf("%c %c\n", ans[i].first+'a', ans[i].second+'a');
    }

}