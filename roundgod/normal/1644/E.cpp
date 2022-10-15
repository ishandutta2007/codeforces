#include<bits/stdc++.h>
#define MAXN 200005
#define INF 100000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cin>>str;
		int down=0,right=0,x=1,y=1;
		for(int i=0;i<(int)str.size();i++)
		{
			if(str[i]=='R') y++;
			else x++;
		}
		down=n-x; right=n-y;
		x=1; y=1;
		ll ans=(int)str.size()+1;
		bool canright=false,candown=false;
		for(int i=0;i<(int)str.size();i++)
		{
			if(str[i]=='D')
			{
				if(canright) ans+=right;
				x++;
				candown=true;
			}
			else 
			{
				if(candown) ans+=down;
				y++;
				canright=true;
			}
		}
		if(canright) ans+=right;
		if(candown) ans+=down;
		if(canright&&candown) ans+=1LL*right*down;
		printf("%lld\n",ans);
	}
	return 0;
}