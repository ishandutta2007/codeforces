#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int L,R;
struct node
{
    int u,v,cost;
};
vector<node> v;
void construct(int num)
{
    for(int i=2;i<=num;i++)
    {
        int now;
        if(i==2) now=1; else now=(1<<(i-3));
        for(int j=i-1;j>=1;j--)
        {
            v.push_back((node){j,i,min(1000000,now)});
            if(now>1) now>>=1;
        }
    }
}
int main()
{
    scanf("%d%d",&L,&R);
    int need=R-L+1;
    int x=1,cnt=2;
    while(x*2<=need) x=x*2,cnt++;
    puts("YES");
    v.clear();
    construct(cnt);
    if(x<need)
    {
        cnt++;
        int rem=need,cur=x;
        for(int i=cnt-1;i>=1;i--)
        {
            if(!rem) break;
            if(rem>=2*cur||((rem&cur)&&(rem!=cur)))
            {
                v.push_back((node){i,cnt,rem-cur});
                rem-=cur;
            }
            cur>>=1;
        }
    }
    if(L==1)
    {
        printf("%d %d\n",cnt,(int)v.size());
        for(auto p:v) printf("%d %d %d\n",p.u,p.v,p.cost);
    }
    else
    {
        printf("%d %d\n",cnt+1,(int)v.size()+1);
        printf("%d %d %d\n",1,2,L-1);
        for(auto p:v) printf("%d %d %d\n",p.u+1,p.v+1,p.cost);
    }
    return 0;
}