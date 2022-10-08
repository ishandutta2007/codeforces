#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,x[111],y[111],c[111];vector<int> a[111];
bool intS(int x1,int y1,int x2,int y2)
{
    if(x1>y1)swap(x1,y1);
    if(x2>y2)swap(x2,y2);
    if(x2<x1&&x1<y2&&y2<y1)return 1;
    if(x1<x2&&x2<y1&&y1<y2)return 1;
    return 0;
}
void ff(int x,int y)
{
    c[x]=y;
    for(vector<int>::iterator i=a[x].begin();i!=a[x].end();i++)
        if(c[*i]==y)throw 0;else
        if(c[*i]==-1)ff(*i,y^1);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d%d",x+i,y+i);
    for(int i=0;i<m;i++)
        for(int j=0;j<i;j++)
            if(intS(x[i],y[i],x[j],y[j]))
                a[i].push_back(j),a[j].push_back(i);
    memset(c,-1,sizeof c);
    for(int i=0;i<m;i++)
        if(c[i]==-1)
            try{ff(i,0);}catch(...){puts("Impossible");return 0;}
    for(int i=0;i<m;i++)printf("%c",c[i]?'i':'o');
    puts("");
    return 0;
}