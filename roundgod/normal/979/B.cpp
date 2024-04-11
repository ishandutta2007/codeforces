#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,len;
string str1,str2,str3;
int cnt[200];
int main()
{
	scanf("%d",&n);
	cin>>str1;
	cin>>str2;
	cin>>str3;
	len=str1.size();
	int cnt1=0,cnt2=0,cnt3=0;
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<len;i++)
	{
		cnt[str1[i]-'A']++;
		//printf("%d\n",str1[i]-'A');
		cnt1=max(cnt1,cnt[str1[i]-'A']);
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<len;i++)
	{
		cnt[str2[i]-'A']++;
		cnt2=max(cnt2,cnt[str2[i]-'A']);
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<len;i++)
	{
		cnt[str3[i]-'A']++;
		cnt3=max(cnt3,cnt[str3[i]-'A']);
	}
	if(n==1)
	{
		if(cnt1==len) cnt1=len-1; else cnt1++;
		if(cnt2==len) cnt2=len-1; else cnt2++;
		if(cnt3==len) cnt3=len-1; else cnt3++;
	}
	else
	cnt1=min(cnt1+n,len),cnt2=min(cnt2+n,len),cnt3=min(cnt3+n,len);
	//printf("%d %d %d\n",cnt1,cnt2,cnt3);
	if(cnt1>cnt2&&cnt1>cnt3) puts("Kuro");
	else if(cnt2>cnt1&&cnt2>cnt3) puts("Shiro");
	else if(cnt3>cnt1&&cnt3>cnt2) puts("Katie");
	else puts("Draw");
	return 0;
}