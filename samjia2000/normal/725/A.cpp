#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int get(){
	char ch;
	int s=0;
	bool bz=0;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-')bz=1;else s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	if (bz)return -s;
	return s;
}

const int N = 2e+5+10;

char s[N];
int n;

int main(){
	n=get();
	fo(i,1,n)while(s[i]=getchar(),s[i]!='<'&&s[i]!='>');
	int ans=0;
	fo(i,1,n)
	if (s[i]=='>'){ans+=i-1;break;}
	fd(i,n,1)
	if (s[i]=='<'){ans+=n-i;break;}
	bool bz=1;
	fo(i,2,n)bz&=(s[i]==s[i-1]);
	if (bz)ans=n;
	printf("%d\n",ans);
	return 0;
}