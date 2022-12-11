#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define se second
#define fi first

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 200005;

int a[N],b[N];

int main(){
	int n=get();
	int cnt0=0,cnt1=0;
	fo(i,1,n){
		int x=get();
		int u=sqrt(x);
		if (u*u==x){
			cnt0++;
			if (x==0)b[cnt0]=2;
			else b[cnt0]=1;
		}
		else{
			cnt1++;
			a[cnt1]=min(x-u*u,(u+1)*(u+1)-x);
		}
	}
	sort(a+1,a+1+cnt1);
	sort(b+1,b+1+cnt0);
	if (cnt0>cnt1){
		LL ans=0;
		fo(i,1,(cnt0-cnt1)/2)ans=ans+b[i];
		printf("%I64d\n",ans);
	}
	else{
		LL ans=0;
		fo(i,1,(cnt1-cnt0)/2)ans=ans+a[i];
		printf("%I64d\n",ans);
	}
	return 0;
}