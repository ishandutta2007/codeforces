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
typedef unsigned int ui;

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

const int N = 1e+5+5;

int n,a[N],m;
ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}

LL quickmi(LL x,LL tim){
	x%=m;
	LL ans=1;
	for(;tim;tim/=2,x=x*x%m)
	if (tim&1)ans=ans*x%m;
	return ans;
}

set<int>s;

int getid(int x){
	s.clear();
	int cnt=0;
	fo(i,1,n)
	if (i!=x){
		int v=(a[i]+m-a[x])%m;
		if (s.find(v)!=s.end())cnt++;
		s.insert((a[x]+m-a[i])%m);
	}
	return cnt+1;
}

int b[N];

bool check(int x1,int d){
	b[1]=x1;
	fo(i,2,n)b[i]=(b[i-1]+d)%m;
	sort(b+1,b+1+n);
	fo(i,1,n)
	if (a[i]!=b[i])return 0;
	return 1;
}

int main(){
	m=get();n=get();
	fo(i,1,n)a[i]=get();
	if (m==n)return printf("0 1\n"),0;
	sort(a+1,a+1+n);
	if (n==1)return printf("%d 0\n",a[1]),0;
	if (n==2)return printf("%d %d\n",a[1],a[2]-a[1]),0;
	int x1=a[1],d=0;
	seed=23423839;
	int tim=0;
	bool rev=0;
	if (2*n>=m){
		rev=1;
		bool ext[N*2];
		fo(i,0,m-1)ext[i]=0;
		fo(i,1,n)ext[a[i]]=1;
		n=0;
		fo(i,0,m-1)
		if (!ext[i])a[++n]=i;
		sort(a+1,a+1+n);
	}
	if (n==1)x1=a[1],d=1;
	if (n==2)x1=a[1],d=a[2]-a[1];
	if (n>=3){
			tim++;
			int x=getrand()%n+1,y=getrand()%n+1;
			while(x==y)x=getrand()%n+1,y=getrand()%n+1;
			int xid=getid(x),yid=getid(y);
			d=1ll*(a[y]+m-a[x])%m*quickmi((yid+m-xid)%m,m-2)%m;
			x1=(a[x]+m-1ll*(xid-1)*d%m)%m;
			if (!check(x1,d)){
				yid=n-yid+1;
				d=1ll*(a[y]+m-a[x])%m*quickmi((yid+m-xid)%m,m-2)%m;
				x1=(a[x]+m-1ll*(xid-1)*d%m)%m;
			}
	}
	if (!check(x1,d))printf("-1\n");
	else{
		if (rev){
			x1=(x1+1ll*n*d%m)%m;
			n=m-n;
		}
		if (d>m/2){
			x1=(x1+1ll*(n-1)*d%m)%m;
			d=m-d;
		}
		printf("%d %d\n",x1,d);
	}
	return 0;
}