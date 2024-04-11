#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,p,x;
set<int> s;
int fib[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
	fib[0]=1;
	fib[1]=2;
	for(int i=2;i<=200000;i++)
	{
		fib[i]=1;
		add(fib[i],fib[i-1]);
		add(fib[i],fib[i-2]);
	}
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s.insert(x);
	}
	int ans=0;
	for(auto x:s)
	{
		int tmp=x;
		bool f=false;
		while(tmp%4==0||tmp%2==1)
		{
			if(tmp==0) break;
			if(tmp%4==0) tmp/=4;
			else tmp/=2;
			if(s.count(tmp)) {f=true; break;}
		}
		if(!f)
		{
			int t=1,cnt=1;
			while(2*t<=x) t*=2,cnt++;
			if(cnt>p) continue;
			int num=p-cnt;
			add(ans,fib[num]);
		}
	}
	printf("%d\n",ans);
	return 0;
}