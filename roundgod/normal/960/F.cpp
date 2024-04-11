#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
map<int,int> bit[MAXN];
int cal(int num,int i)
{
    int s=0;
    while(i>0)
    {
        if(bit[num].find(i)!=bit[num].end()) s=max(s,bit[num][i]);
        i-=i&-i;
    }
    return s;
}
void change(int num,int i,int x)
{
    while(i<MAXN)
    {
        bit[num][i]=max(bit[num][i],x);
        i+=i&-i;
    }
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		u--;v--;
		int res=cal(u,w);
		//printf("%d\n",res);
		change(v,w+1,res+1);
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans,cal(i,MAXN-1));
	printf("%d\n",ans);
	return 0;
}