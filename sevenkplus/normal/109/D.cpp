#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define N 100010
#define pb push_back
#define fi first
#define se second
#define mp make_pair
int n,a[N],b[N],c[N],p=-1;set<int> A;vector<pair<int,int> > B;
bool cmp(int x,int y){return a[x]<a[y];}
void mov(int x,int y)
{
    if(x==y)return;
    B.pb(mp(x+1,y+1));
    int _x=c[x],_y=c[y];
    swap(a[x],a[y]);
    swap(b[_x],b[_y]);
    swap(c[x],c[y]);
    if(x==p)p=y;else
    if(y==p)p=x;
}
int main()
{
    for(int i=1;i<=9;i++)
        for(int k=0;k<(1<<i);k++)
        {
            int x=0;
            for(int j=0;j<i;j++)
                if((k>>j)&1)x=x*10+4;else x=x*10+7;
            A.insert(x);
        }
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i),b[i]=i;
    sort(b,b+n,cmp);
    for(int i=0;i<n;i++)c[b[i]]=i;
    for(int i=0;i<n;i++)if(A.find(a[i])!=A.end())p=i;
    if(p==-1)
    {
        for(int i=0;i<n-1;i++)if(a[i+1]<a[i]){puts("-1");return 0;}
        puts("0");return 0;
    }
    for(int i=0;i<n;i++)
        if(b[i]!=p)mov(p,i),mov(b[i],p);
    printf("%d\n",(int)B.size());
    for(int i=0;i<(int)B.size();i++)printf("%d %d\n",B[i].fi,B[i].se);
    return 0;
}