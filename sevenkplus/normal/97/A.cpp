#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,m,cx[100],cy[100],S,g[100][100],c[100];char a[100][100];
void ff(int x,int y)
{
    if(x==14)
    {
        set<pair<int,int> > A;
        for(int i=0;i<28;i++)
        {
            pair<int,int> p=make_pair(c[cx[i]],c[cy[i]]);
            if(p.first>p.second)swap(p.first,p.second);
            if(A.find(p)!=A.end())return;
            A.insert(p);
        }
        S++;
        if(S==1)
        {
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    if(g[i][j]==-1)a[i][j]='.';
                    else a[i][j]=c[g[i][j]]+'0';
        }
        return;
    }
    if(c[x]!=-1){ff(x+1,y);return;}
    c[x]=y;
    for(int i=x+1;i<14;i++)
        if(c[i]==-1)c[i]=y,ff(x+1,y+1),c[i]=-1;
    c[x]=-1;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(cx,-1,sizeof cx),
    memset(cy,-1,sizeof cy),
    memset(g,-1,sizeof g);
    for(int i=0,w=0;i<n;i++)
    {
        char s[100];scanf("%s",s);
        for(int j=0;j<m;j++)
            if(s[j]!='.')
            {
                if(g[i][j]==-1)g[i][j]=g[i][j+1]=g[i+1][j]=g[i+1][j+1]=w++;
                int p=s[j]-'a';
                if(s[j]=='A')p=26;else
                if(s[j]=='B')p=27;
                if(cx[p]==-1)cx[p]=g[i][j];else cy[p]=g[i][j];
            }
    }
    memset(c,-1,sizeof c),ff(0,0);
    printf("%d\n",S*5040);
    for(int i=0;i<n;i++)printf("%s\n",a[i]);
    return 0;
}