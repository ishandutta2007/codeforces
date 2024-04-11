#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string x,y;
int p[MAXN],r[MAXN];
P ans[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
	scanf("%d",&n);
	cin>>x>>y;
	init(26);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(same(x[i]-'a',y[i]-'a')) continue;
		else
		{
			ans[cnt].F=x[i]-'a';
			ans[cnt].S=y[i]-'a';
			cnt++;
			unite(x[i]-'a',y[i]-'a');
		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
		printf("%c %c\n",ans[i].F+'a',ans[i].S+'a');
	return 0;
}