#include<bits/stdc++.h>
#define MAXN 55
using namespace std;
int n,m;
int a[MAXN];
int perm[4];
char mp[MAXN][MAXN];
char str[105];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",mp[i]);
    for(int i=0;i<4;i++)
        perm[i]=i;
    scanf("%s",str);
    int len=strlen(str);
    int stx,sty;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mp[i][j]=='S') {stx=i;sty=j;}
    int cnt=0;
    for(int i=0;i<24;i++)
    {
        bool f=false;
        int x=stx,y=sty;
        for(int j=0;j<len;j++)
        {
            int dir=perm[str[j]-'0'];
            if(dir==0) x++;
            else if(dir==1) y++;
            else if(dir==2) x--;
            else if(dir==3) y--;
            if(x<0||y<0||x>=n||y>=m||mp[x][y]=='#') break;
            if(mp[x][y]=='E') {f=true;break;}
        }
        if(f) cnt++;
        next_permutation(perm,perm+4);
    }
    printf("%d\n",cnt);
    return 0;
}