/*
ID: Sfiction
OJ: CF
PROB: 208B
*/
#include <cstdio>

const int MAXN=52;

int n;
char card[MAXN][3];
bool vis[MAXN][MAXN][MAXN][MAXN];

bool Check(int i,int j){
    return card[i][0]==card[j][0] || card[i][1]==card[j][1];
}

bool DFS(int deep,int i,int j,int k){
    if (vis[deep][i][j][k])
        return 0;
    if (deep==2)
            return Check(i,k) && Check(j,k);
    if (Check(j,k) && DFS(deep-1,deep-3,i,k))
        return true;
    if (Check(deep-3,k) && DFS(deep-1,k,i,j))
        return true;
    vis[deep][i][j][k]=true;
    return false;
}

int main(){
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%s",card[i]);
    if (n==1)
        printf("YES");
    else
        printf((n==2 ? Check(0,1) : DFS(n-1,n-3,n-2,n-1)) ? "YES" : "NO");
    return 0;
}