#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,l,r,n;
bool f;
int ans;
int tot,trie[MAXN][2];
int cnt[MAXN];
void insert(int val)
{
	int rt=1; cnt[1]++;
    for(int i=0;i<17;i++)
    {
        int x=(val>>(16-i))&1;
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        rt=trie[rt][x];
		cnt[rt]++;
    }
}
void clear()
{
	for(int i=1;i<=tot;i++) trie[i][0]=trie[i][1]=0,cnt[i]=0;
	tot=1;
}
int solve(int val,int r)
{
	if(r<0) return 0;
	int rt=1,res=0;
    for(int i=0;i<17;i++)
    {
        int x=(val>>(16-i))&1,y=(r>>(16-i))&1;
        if(y==0)
        {
        	rt=trie[rt][x];
        	if(!rt) return res;
        }
        else
        {
        	res+=cnt[trie[rt][x]];
        	rt=trie[rt][x^1];
        	if(!rt) return res;
        }
    }
    res+=cnt[rt];
    return res;
}
bool check(int val)
{
	return (solve(val,r)-solve(val,l-1))==(r-l+1);
}
int main()
{
	tot=1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		n=r-l+1;
		clear();
		int x;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			insert(x);
		}
		for(int i=l;i<=r;i++) if(check(i^x)) {printf("%d\n",i^x); break;}
	}
	return 0;
}