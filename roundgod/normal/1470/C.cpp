#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int val[MAXN],tmp[MAXN];
mt19937 wcy(time(NULL));
vector<int> valid;
void init()
{
    for(int i=1;i<=n;i++) val[i]=k;
    for(int i=1;i<=n;i++) valid.push_back(i);
}
void update()
{
    for(int i=1;i<=n;i++) tmp[i]=0;
    for(int i=2;i<=n;i++) 
    {
        int l=i-1,r=i+1;
        if(r>n) r=1;
        tmp[l]+=val[i]/2; tmp[r]+=(val[i]+1)/2;
    } 
    tmp[2]+=val[1];
    for(int i=1;i<=n;i++) val[i]=tmp[i];
}
int ask(int q)
{
    printf("? %d\n",q);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return x;
}
void answer()
{
    printf("! %d\n",valid[0]);
    fflush(stdout);
    exit(0);
}
void check(int x,int y)
{
    vector<int> tmp; tmp.clear();
    for(int i=0;i<(int)valid.size();i++)
    {
        int shift=x-valid[i]+1;
        if(shift<=0) shift+=n;
        if(shift>n) shift-=n;
        if(val[shift]==y) tmp.push_back(valid[i]);
    }
    swap(tmp,valid);
}
void choose()
{
    assert(valid.size()!=0);
    if(valid.size()==1) answer();
    int x=wcy()%(int)valid.size();
    int y=wcy()%(int)valid.size();
    while(x==y) y=wcy()%(int)valid.size();
    int id=-1;
    x=valid[x]; y=valid[y];
    if(x>y) swap(x,y); 
    for(int i=1;i<=n;i++)
    {
        int r=(i+y-x)%n;
        if(r==0) r=n;
        if(val[i]!=val[r])
        {
            id=i;
            break;
        }
    }
    if(id!=-1)
    {
        id=(id+x-1)%n;
        if(id==0) id=n;
    }
    else id=wcy()%n+1;
    check(id,ask(id));
    update();
}
int main()
{
    scanf("%d%d",&n,&k);
    init();
    for(int i=1;i<=1000;i++) choose();
    assert(0);
    return 0;
}