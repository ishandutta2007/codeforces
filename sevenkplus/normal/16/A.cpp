#include<cstdio>
char s[100][100];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    bool f=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m-1;j++)
            f&=s[i][j]==s[i][j+1];
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m;j++)
            f&=s[i][j]!=s[i+1][j];
    puts(f?"YES":"NO");
    return 0;
}