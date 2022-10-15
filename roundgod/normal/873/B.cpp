#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,sum[MAXN],fst[MAXN];
string str;
int main()
{
	scanf("%d",&n);
	cin>>str;
	memset(fst,-1,sizeof(fst));
	int ans=0,cnt=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0') cnt++; else cnt--;
		if(cnt==0) ans=max(ans,i+1);
		int id=cnt+100000;
		if(fst[id]!=-1) ans=max(ans,i-fst[id]); else fst[id]=i;
	}
	printf("%d\n",ans);
	return 0;
}