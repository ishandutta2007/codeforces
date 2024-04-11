#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<vector>

using namespace std;
int n,m,a,b,c,d;
char S[233333],T[233333];
int ss[233333],st[233333];
vector<int> vs,vt;
int main()
{
	scanf(" %s %s",S+1,T+1);
	int ls=strlen(S+1),lt=strlen(T+1);
	for(int i=1;i<=ls;i++)ss[i]=ss[i-1]+(S[i]=='B'||S[i]=='C');
	for(int i=1;i<=lt;i++)st[i]=st[i-1]+(T[i]=='B'||T[i]=='C');
	vs.push_back(0);vt.push_back(0);
	for(int i=1;i<=ls;i++)if(S[i]=='B'||S[i]=='C')vs.push_back(i);
	for(int i=1;i<=lt;i++)if(T[i]=='B'||T[i]=='C')vt.push_back(i);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if((ss[b]-ss[a-1])%2!=(st[d]-st[c-1])%2)printf("0");
		else if(ss[b]-ss[a-1]>st[d]-st[c-1])printf("0");
		else
		{
			int l=0,r=vs.size()-1;
			while(l<r)
			{
				int mid=(l+r+1)>>1;
				if(vs[mid]>b)r=mid-1;
				else l=mid;
			}
			int cnts=b-max(vs[l],a-1);
//			cout<<vs[l]<<' '<<cnts<<endl;
			l=0,r=vt.size()-1;
			while(l<r)
			{
				int mid=(l+r+1)>>1;
				if(vt[mid]>d)r=mid-1;
				else l=mid;
			}
			int cntt=d-max(vt[l],c-1);
			if(ss[b]-ss[a-1]==st[d]-st[c-1])
			{
				if(cnts<cntt)printf("0");
				else if(cnts%3!=cntt%3)printf("0");
				else printf("1");
			}
			else if(ss[b]-ss[a-1]==0)
			{
			    if(cnts<=cntt)printf("0");
			    else printf("1");
			}
			else if(cnts<cntt)printf("0");
			else printf("1");
		}
	}
	return 0;
}