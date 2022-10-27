#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100000 + 10;
int n;
vector<int> g[N];
int sum[N],deg[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v); g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(deg[i]==2) {
            return !printf("NO\n");
        }
    }
    printf("YES\n");
}
/*
1
2 3 4
5 6
*/