#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> ans1,ans2,ans3;
int main()
{
	scanf("%d",&n);
	bool f=false,flag=false;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>0) flag=true;
	}
	if(flag)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]>0) ans2.push_back(a[i]);
			if(a[i]<0)
			{
				if(!f) {ans1.push_back(a[i]); f=true;}
				else ans3.push_back(a[i]);		
			}
			if(a[i]==0) ans3.push_back(a[i]);
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]<0)
			{
				if(!f) {ans1.push_back(a[i]); f=true;}
				else if(ans2.size()<2) ans2.push_back(a[i]);
				else ans3.push_back(a[i]);		
			}
			if(a[i]==0) ans3.push_back(a[i]);
		}
	}
	sort(ans1.begin(),ans1.end());
	sort(ans2.begin(),ans2.end());
	sort(ans3.begin(),ans3.end());
	printf("%d ",ans1.size()); for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]); puts("");
	printf("%d ",ans2.size()); for(int i=0;i<ans2.size();i++) printf("%d ",ans2[i]); puts("");
	printf("%d ",ans3.size()); for(int i=0;i<ans3.size();i++) printf("%d ",ans3[i]); puts("");
	return 0;
}