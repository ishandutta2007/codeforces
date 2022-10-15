#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,mask;
mt19937 wcy(time(NULL));
vector<int> indices;
int ans[MAXN];
int ask(int i,int j)
{
    printf("? %d %d\n",i,j);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
void update(int nmask,int pos)
{
    vector<int> tmp;
    mask=nmask;
    for(auto x:indices)
    {
        if(x==pos) tmp.push_back(x);
        else if((ask(x,pos)|nmask)==nmask) tmp.push_back(x);
    }
    indices=tmp;
}
void answer()
{
    printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    printf("\n");
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    mask=1;
    while(mask<n) mask=mask*2+1;
    for(int i=1;i<=n;i++) indices.push_back(i);
    while(__builtin_popcount(mask)>1)
    {
        int sz=(int)indices.size();
        int x=wcy()%sz,y=wcy()%sz;
        while(y==x) y=wcy()%sz;
        int res=ask(indices[x],indices[y]);
        if(__builtin_popcount(res)*2<=__builtin_popcount(mask))
        {
            update(res,indices[y]);
        }
    }
    assert(indices.size()==2);
    int x=indices[0];
    bool f=true;
    for(int i=0;i<30;i++)
    {
        int y=wcy()%n+1;
        while(y==x) y=wcy()%n+1;
        if((ask(x,y)&mask)==0) {f=false; break;}
    }
    if(f) x=indices[1];
    for(int i=1;i<=n;i++)
    {
        if(i==x) ans[i]=0; else ans[i]=ask(i,x);
    }
    answer();
    return 0;
}