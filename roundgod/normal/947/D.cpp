#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s,t;
int q;
int sum1[MAXN],sum2[MAXN],num1[MAXN],num2[MAXN],ans[MAXN];
int main()
{
	cin>>s;
	cin>>t;
	sum1[0]=sum2[0]=0;
	int now=0;
	bool f=false;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='A') 
		{
			if(!f) {f=true; now=i+1; num1[i+1]=now;}
			else num1[i+1]=now;
		}
		if(s[i]!='A') {num1[i+1]=-1; f=false;}
		sum1[i+1]=sum1[i]+(s[i]=='A'?0:1);
	}
	now=0;f=false;
	for(int i=0;i<t.size();i++)
	{
		if(t[i]=='A') 
		{
			if(!f) {f=true; now=i+1; num2[i+1]=now;}
			else num2[i+1]=now;
		}
		if(t[i]!='A') {num2[i+1]=-1; f=false;}
		sum2[i+1]=sum2[i]+(t[i]=='A'?0:1);
	}
	scanf("%d",&q);
	int a,b,c,d;
	for(int i=0;i<q;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int cnt1=sum1[b]-sum1[a-1];
		int cnt2=sum2[d]-sum2[c-1];
		int len1,len2;
		if(num1[b]==-1) len1=0; else len1=b-max(num1[b],a)+1;
		if(num2[d]==-1) len2=0; else len2=d-max(num2[d],c)+1;
		if(len1<len2||cnt1>cnt2||((cnt1&1)!=(cnt2&1)))
		{
			ans[i]=0;
			continue;
		}
		if(cnt1==cnt2) ans[i]=(((len1%3)==(len2%3))&&(len1>=len2))?1:0;
		else if(cnt1==0) ans[i]=(cnt2!=0&&len1>len2)?1:0;
		else ans[i]=1;
	}
	for(int i=0;i<q;i++)
		printf("%d",ans[i]);
	puts("");
	return 0;
}