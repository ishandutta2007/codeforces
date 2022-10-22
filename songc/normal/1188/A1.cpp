#include <bits/stdc++.h>
using namespace std;

int N;
int deg[101010];

int main(){
    int u, v;
    scanf("%d", &N);
    for (int i=1; i<N; i++){
        scanf("%d %d", &u, &v);
        deg[u]++, deg[v]++;
    }
    for (int i=1; i<=N; i++) if (deg[i] == 2){
        puts("NO");
        return 0;
    }
    puts("YES");
    return 0;
}