#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
string str;
bool C(int x)
{
	bool num[10];
	memset(num,false,sizeof(num));
	string S="";
	for(int i=0;i<x;i++)
		num[str[i]-'0']=!num[str[i]-'0'];
	int cnt=0;
	for(int i=0;i<10;i++)
		if(num[i]) cnt++;
	if(cnt>str.size()-x) return false;
	for(int i=0;i<10;i++)
		if(num[i]) S+=(char)(i+'0');
	int len=str.size()-x;
	for(int i=S.size();i<len;i++)
		S='0'+S;
	return S<str.substr(x,len); 
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cin>>str;
		bool f=true;
		if(str[0]!='1') f=false;
		for(int i=1;i<str.size()-1;i++)
			if(str[i]!='0') f=false;
		if(str[str.size()-1]>'1') f=false;
		if(f)
		{
			for(int i=0;i<str.size()-2;i++)
				printf("9");  
			puts("");
			continue;
		}
		f=false;
		int l=0,r=str.size();
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(C(mid)) l=mid; else r=mid;
		}
		int t=-1;
		bool num[10];
		for(int i=str[l]-'0'-1;i>=0;i--)
		{
			memset(num,false,sizeof(num));
			string S="";
			for(int j=0;j<l;j++)
				num[str[j]-'0']=!num[str[j]-'0'];
			num[i]=!num[i];
			int cnt=0;
			for(int j=0;j<10;j++)
				if(num[j]) cnt++;
			if(cnt>str.size()-l-1) continue;
			S+=(char)(i+'0');
			for(int j=0;j<10;j++)
				if(num[j]) S+=(char)(j+'0');
			int len=str.size()-l;
			for(int j=S.size();j<len;j++)
				S='0'+S;
			if (S<str.substr(l,len)) {t=i; break;} 
		}
		for(int i=0;i<l;i++)
			printf("%c",str[i]);
		printf("%d",t);
		memset(num,false,sizeof(num));
		num[t]=true;
		for(int i=0;i<l;i++)
			num[str[i]-'0']=!num[str[i]-'0'];
		int cnt=0,len=str.size()-l-1;
		for(int i=0;i<10;i++)
			if(num[i]) cnt++;
		for(int i=0;i<len-cnt;i++)
			printf("9");
		for(int i=9;i>=0;i--)
			if(num[i]) printf("%d",i);
		puts("");
	}
	return 0;
}