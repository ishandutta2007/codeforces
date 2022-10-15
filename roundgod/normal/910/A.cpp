#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d;
string str;
int main()
{
	scanf("%d%d",&n,&d);
	cin>>str;
	int cnt=0,now=0;
	while(now<n-1)
	{
		bool f=false;
		for(int i=min(now+d,n-1);i>=now+1;i--)
			if(str[i]=='1') {f=true; now=i; cnt++; break;}
		if(!f)
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",cnt);
	return 0;
}