//In the name of God
#include <iostream>
#include <cstdio>
using namespace std;
const int Maxn = 1e6 + 1e3;
int deg[Maxn];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        deg[--u]++;
        deg[--v]++;
    }
    long long ans = ((long long)n*(n-1)*(n-2))/6;
    long long minus = 0;
    for(int i = 0; i < n;i++){
        minus += ((long long)n-deg[i]-1)*(deg[i]);
    }
    cout << ans - minus/2 << endl;
    return 0;
}