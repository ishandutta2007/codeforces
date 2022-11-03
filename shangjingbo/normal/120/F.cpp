#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

const int maxn = 128;

vector<int> adj[maxn];
int n;

int len[maxn];

int bfs(int src)
{
    memset(len, -1, sizeof(len));
    len[src] = 0;
    queue<int> Q;
    Q.push(src);
    int last = -1;
    while (!Q.empty()) {
        int p = Q.front();
        Q.pop();
        last = p;
        for (int i = 0; i < adj[p].size(); i++) {
            int q = adj[p][i];
            if (len[q] == -1) {
                len[q] = len[p] + 1;
                Q.push(q);
            }
        }
    }
    return last;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int trees;
    scanf("%d", &trees);
    int sum = 0;
    while (trees --) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            adj[i].clear();
        for (int i = 1; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        sum += len[bfs(bfs(0))];
    }
    printf("%d\n", sum);
}