#include <bits/stdc++.h>
using namespace std;

typedef pair<char, char> pc;
int n;
string str1, str2;
vector<int> G[30];
vector<pc> res;
bool vis[30];

int ch(char a){return a-'a';}
char cr(int a){return char(a+'a');}

void dfs(int v, int p){
    if(p != -1) res.push_back(pc(cr(p),cr(v)));
    vis[v] = true;
    for(int nxt : G[v]){
        if(!vis[nxt]) dfs(nxt, v);
    }
}

int main() {
    scanf("%d", &n);
    getchar();
    getline(cin, str1);
    getline(cin, str2);
    fill(vis, vis+30, false);
    for(int i = 0; i < n; i++){
        if(str1[i] != str2[i]){
            char c1 = str1[i], c2 = str2[i];
            G[ch(c1)].push_back(ch(c2));
            G[ch(c2)].push_back(ch(c1));
        }
    }
    for(int i = 0; i < 26; i++) dfs(i, -1);
    cout << res.size() << endl;
    for(pc pci : res) cout << pci.first << " " << pci.second << endl;
}