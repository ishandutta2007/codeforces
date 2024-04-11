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

const int N = 6400000;

int n;
int a[N];
struct position{
	int w,v;
	friend bool operator < (position a,position b){
		return a.w<b.w;
	}
}s[N];
int k;
LL mx;
LL sum;

int main(){
	n=get();scanf("%lld",&mx);
	sum=0;
	fo(i,1,n){
		int x=get();
		if (x==1){
			sum++;
			s[++k].w=1;
			s[k].v=1;
			continue;
		}
		for(int now=1,lst=0;now<x;now=(x-1)/((x-1)/now)+1){
			int v=(x-1)/now+1;
			s[++k].w=now;
			s[k].v=v-lst;
			lst=v;
		}
		s[++k].w=x;
		s[k].v=-1;
		sum=sum+x;
	}
	sort(s+1,s+1+k);
	LL now=0;
	LL ans;
	fo(i,1,k){
		now=now+s[i].v;
		if (i==k||s[i].w<s[i+1].w){
			LL r;
			if (i==k)r=1e+12;else r=s[i+1].w-1;
			LL d=(mx+sum)/now;
			if (d>=s[i].w&&d<=r)ans=d;
		}
	}
	printf("%lld\n",ans);
	return 0;
}