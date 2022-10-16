#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
string buf;
int vis[10];
int cnt[11];
int t[11]={100000,10000,1000,100,10,1};
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>buf;
		vis[buf[0]-'a']=1;
		int l=buf.length();
		for(int j=0;j<l;j++)
		{
			cnt[buf[j]-'a']+=t[6-l+j];
		}
	}
	//for(int i=0;i<10;i++)cout<<cnt[i]<<' ';cout<<endl;
	int qwq[10]={0,1,2,3,4,5,6,7,8,9};
	int ans=2147483645;
	do
	{
		int f=0;
		for(int i=0;i<10;i++)
		{
			if(vis[i]&&qwq[i]==0)f=1;
		}
		if(f==1)continue;
		int tmp=0;
		for(int i=0;i<10;i++)
		{
			//cout<<qwq[i]<<' ';
			tmp+=cnt[i]*qwq[i];
		}
		//cout<<tmp<<endl;
		ans=min(ans,tmp);
	}
	while(next_permutation(qwq,qwq+10));
	printf("%d\n",ans);
	return 0;
}