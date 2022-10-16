#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
int pr[23333],fl[23333],top;
const long long lim=1000000000000000000ll;
int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=2;i<=10000;i++)
	{
		if(!fl[i])pr[++top]=i;
		for(int j=i+i;j<=10000;j+=i)fl[j]=1;
	}
	cin>>T;
	while(T--)
	{
		int qcnt=0,cur=1,last=1,ans=1;
		int zz=0;
		while(qcnt<=20)
		{
			long long tmp=1,gg;
			while((__int128)tmp*pr[cur]<=lim)tmp*=pr[cur],cur++;
			qcnt++;
			cout<<"? "<<tmp<<endl;
			cin>>gg;
			for(int i=last;i<cur;i++)
			{
				if(gg%pr[i]==0)
				{
					if(!zz)zz=pr[i];
					else if(qcnt<=20)
					{
						long long xx=1,yy=1,ggg;
						while(xx*zz<=1e9)xx*=zz;
						while(yy*pr[i]<=1e9)yy*=pr[i];
						qcnt++;
						cout<<"? "<<xx*yy<<endl;
						cin>>ggg;
						int cnt=1;
						while(ggg%zz==0)ggg/=zz,cnt++;
						ans*=cnt;
						cnt=1;
						while(ggg%pr[i]==0)ggg/=pr[i],cnt++;
						ans*=cnt;
						zz=0;
					}
					else ans*=2;
				}
			}
			last=cur;
		}
		if(zz)
		{
			long long xx=1,ggg;
			while(xx*zz<=1e9)xx*=zz;
			qcnt++;
			cout<<"? "<<xx<<endl;
			cin>>ggg;
			int cnt=1;
			while(ggg%zz==0)ggg/=zz,cnt++;
			ans*=cnt;
		}		
//		cerr<<pr[cur]<<' '<<ans<<endl;
		cout<<"! "<<max(ans*2,ans+7)<<endl;
	}
	return 0;
}