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

const int N = 100005;

int n,d,b;
struct section{
	int l,r,v;
}s[N];
int nv[N];
int tim[N];
int a[N];

bool check(int lim){
	int l=max(0,n/2+(n&1)-lim),r=max(0,n/2-lim);
	fo(i,1,n)nv[i]=s[i].v,a[i]=0;
	int w=1,now=0;
	int lcnt=0,rcnt=0;
	if (l)
	fo(i,1,n/2+(n&1)){
		while(w<=n&&s[w].l<=i&&now<b){
			now=now+nv[w];
			nv[w++]=0;
		}
		if (now>=b){
			lcnt++;
			now=now-b;
			w--;
			nv[w]=nv[w]+now;
			now=0;
			if (lcnt>=l)break;
		}
	}
	w=n,now=0;
	if (r)
	fd(i,n,n/2+(n&1)+1){
		while(w&&s[w].r>=i&&now<b){
			now=now+nv[w];
			nv[w--]=0;
		}
		if (now>=b){
			rcnt++;
			now=now-b;
			w++;
			nv[w]=nv[w]+now;
			now=0;
			if (rcnt>=r)break;
		}
	}
	return lcnt>=l&&rcnt>=r;
}

int main(){
	n=get();d=get();b=get();
	fo(i,1,n)s[i].v=get();
	fo(i,1,n/2+(n&1))tim[i]=i;
	fo(i,1,n/2)tim[n-i+1]=i;
	int w=1;
	fo(i,1,n){
		while(w<n&&tim[w+1]>=(w-i)/d+1)w++;
		s[i].r=w;
	}
	w=n;
	fd(i,n,1){
		while(w>1&&tim[w-1]>=(i-w)/d+1)w--;
		s[i].l=w;
	}
	int l=0,r=n,ret=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))ret=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ret);
	return 0;
}