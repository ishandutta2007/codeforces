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

typedef long long LL;

LL ans;
int k2,k3,k5,k6;

int main(){
	k2=get();k3=get();k5=get();k6=get();
	fo(i,0,min(k2,min(k5,k6)))
	if (LL(256)*i+LL(32)*min(k3,k2-i)>ans)
		ans=LL(256)*i+LL(32)*min(k3,k2-i);
	printf("%I64d\n",ans);
	return 0;
}