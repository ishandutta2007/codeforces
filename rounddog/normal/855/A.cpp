#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 10500

using namespace std;
char s[105][maxn],t[maxn];
int n,l[105];
bool f,g;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",t);
        l[i]=strlen(t);
        for (int j=0;j<l[i];j++) s[i][j]=t[j];
        g=true;
        for (int j=1;j<i;j++)
        if (l[j]==l[i]){
            f=true;
            for (int k=0;k<l[i];k++) if (s[j][k]!=s[i][k]) f=false;
            if (f) g=false;
        }
        if (g) printf("NO\n"); else printf("YES\n");
    }
    return 0;
}