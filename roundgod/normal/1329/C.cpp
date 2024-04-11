#include<bits/stdc++.h>
#define MAXN 3000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,g,h;
int a[MAXN];
bool valid(int id)
{
    while(true)
    {
        if(!a[id*2]&&!a[id*2+1])
        {
            if(id<=(1<<g)-1) return false; else return true;
        }
        if(a[id*2]>a[id*2+1]) id=id*2; else id=id*2+1;
    }
}
void go(int id)
{
    while(true)
    {
        if(!a[id*2]&&!a[id*2+1]) { a[id]=0; return;}
        else
        {
            if(a[id*2]>a[id*2+1]) {a[id]=a[id*2]; id=id*2;}
            else {a[id]=a[id*2+1]; id=id*2+1;}
        }
    }
}
vector<int> ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans.clear();
        scanf("%d%d",&h,&g);
        for(int i=1;i<(1<<h);i++) scanf("%d",&a[i]);
        int cnt=(1<<h)-(1<<g),now=1;
        while(cnt)
        {
            if(valid(now)) {ans.push_back(now); go(now); cnt--;}
            else { now++;}
        }
        ll sum=0;
        for(int i=1;i<(1<<g);i++) sum+=a[i];
        printf("%lld\n",sum);
        for(auto x:ans) printf("%d ",x);
        puts("");
        for(int i=1;i<=(1<<h);i++) a[i]=0;
    }
    return 0;
}