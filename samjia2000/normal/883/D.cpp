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

const int N = 1e+6+5;

int n,ka,a[N],kb,b[N];
char s[N];
int fr[N],fl[N];
int lw[N],rw[N],pw[N];

bool check(int len){
	fo(i,0,n)fr[i]=fl[i]=lw[i]=rw[i]=pw[i]=0;
	int w=1;
	b[kb+1]=n+1;
	fo(i,1,ka){for(;w<=kb&&b[w]<=a[i]+len;w++);rw[i]=w;}
	w=1;
	fo(i,1,ka){for(;w<=kb&&b[w]<=a[i];w++);pw[i]=w;}
	w=0;
	fo(i,1,ka){for(;w<kb&&b[w+1]<a[i]-len;w++);lw[i]=w;}
	if(b[1]>=a[1]-len)fl[pw[1]]=1;
	if(b[1]>=a[1])fr[rw[1]]=1;else fr[1]=1;
	pw[ka+1]=n+1;
	int mx=0;
	fo(i,1,ka-1){
		if (i==1){fd(x,pw[1]-1,1)if(fr[x]){mx=x;break;}}
		else fd(x,pw[i]-1,pw[i-1])if (fr[x]){mx=x;break;}
		bool pre=0;
		fo(x,pw[i+1],min(rw[i+1]-1,pw[i+2]-1))
		if (fl[x]){pre=1;break;}
		if (a[i]+len<a[i+1]){
			fo(x,max(lw[i+1]+1,rw[i]),pw[i+1]-1)if (fr[x]){fl[pw[i+1]]=1;break;}
		}
		else
			if (mx>=lw[i+1]+1)fl[rw[i]]=1;
		fo(x,max(rw[i],pw[i+1]),rw[i+1]-1)
		if (fr[x]){
			fr[rw[i+1]]=1;
			fr[x]=0;
		}
		fo(x,pw[i],pw[i+1]-1)
		if (fl[x]){
			fr[x]=1;
			if (x<pw[i])mx=max(mx,x);
		}
		fr[rw[i+1]]|=pre;
		fo(x,max(pw[i],lw[i+1]+1),pw[i+1]-1)
		if (fl[x]){
			fl[x]=0;
			fl[pw[i+1]]=1;
		}
	}
	return fr[kb+1]|fl[kb+1];
}

int main(){
	n=get();
	scanf("%s",s+1);
	int cnt=0;
	fo(i,1,n){
		if (s[i]=='P')a[++ka]=i;
		if (s[i]=='*')b[++kb]=i;
	}
	if (ka==1){
		int w=a[1];
		int l=0,r=0,lv,rv;
		fd(i,w-1,1)if (s[i]=='*')l++,lv=w-i;
		fo(i,w+1,n)if (s[i]=='*')r++,rv=i-w;
		if (r>l||(r==l&&rv<lv))l=r,lv=rv;
		printf("%d %d\n",l,lv);
		return 0;
	}
	int l=0,r=1e+6,ans=0;
	check(12);
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d %d\n",kb,ans);
	return 0;
}