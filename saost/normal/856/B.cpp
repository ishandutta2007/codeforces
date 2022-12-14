#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6 + 5;
int t, n, nNode, isnRoot[N], nxt[N][26];
string s, str[N];
vector<int> S[N];

void add() {
    int u = 0;
    for(int i=0; i<s.length(); ++i) {
        int nt = s[i] - 'a';
        if (nxt[u][nt] == 0) {
            nxt[u][nt] = ++nNode;
        }
        u = nxt[u][nt];
    }
}

void Init() {
    for(int i=0; i<=nNode; ++i) {
        for(int j=0; j<26; ++j) nxt[i][j] = 0;
        S[i].clear();
        isnRoot[i] = 0;
    }
    nNode = 0;
}

void Enter() {
    scanf("%d\n", &n);
    for(int i=0; i<n; ++i) {
        getline(cin, s);
        add();
        str[i] = s;
    }
}

pair<int,int> DFS(int u) {
    pair<int,int> w = {1, 0};
    for(int v : S[u]) {
        pair<int,int> w2 = DFS(v);
        w.first += w2.second;
        w.second += w2.first;
    }
    w.first = max(w.first, w.second);
    return w;
}

void Process() {
    for(int i=0; i<n; ++i) {
        s = str[i];
        int u = 0, v = nxt[0][s[0] - 'a'];
        for(int j=1; j<s.length(); ++j) {
            int nt = s[j] - 'a';
            if (nxt[u][nt] == 0) break;
            u = nxt[u][nt];
            v = nxt[v][nt];
            if (isnRoot[v] == 0)
                S[u].push_back(v);
            isnRoot[v] = 1;
        }
    }
    int ans = 0;
    for(int i=1; i<=nNode; ++i) if (isnRoot[i] == 0) {
        ans += DFS(i).first;
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d\n", &t);
    while (t--) {
        Init();
        Enter();
        Process();
    }
}