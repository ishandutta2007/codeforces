#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int n,k,seq[MAXN];
string str;
vector<P> que;
int main()
{
	scanf("%d%d",&n,&k);
	int state=0,cnt=0;
	for(int i=0;i<(n-k+1);i++)
	{
		cin>>str;
		if(state==0)
		{
			if(str[0]=='Y') cnt++;
			else
			{
				if(cnt!=0) que.push_back(P(state,cnt));
				cnt=1;
				state=1;
			}
		}
		else
		{
			if(str[0]=='N') cnt++;
			else
			{
				que.push_back(P(state,cnt));
				cnt=1;
				state=0;
			}
		}
	}
	que.push_back(P(state,cnt));
	for(int i=1;i<=k;i++)
		seq[i]=i;
	int t=k+1,now=-1;
	for(int i=0;i<que.size();i++)
	{
		if(que[i].F==0)
		{
			if(now==-1)
				for(int j=0;j<que[i].S;j++)
					{seq[t]=seq[t-k];t++;}
			else
				for(int j=0;j<que[i].S-1;j++)
					{seq[t]=seq[t-k];t++;}
		}
		else
		{
			now=seq[t-k];
			for(int j=0;j<que[i].S;j++)
				{seq[t]=seq[t-k+1];t++;}
			seq[t++]=now;
		}
	}
	for(int i=2;i<=n+1;i++)
		printf("%c%c ",'A'+seq[i]/26,'a'+seq[i]%26);
	printf("\n");
	return 0;
}