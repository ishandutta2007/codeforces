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

const int N = 1e6+5;
const int mo = 1e9+7;

int n,k;
int a[N];
int rmq[N][21],rq[N][21];

int getmax(int l,int r){
	int t=log(r-l+1)/log(2);
	return max(rmq[l][t],rmq[r-(1<<t)+1][t]);
}

int key[N],m,val[N];
LL ans;

int getrq(int l,int r){
	int t=log(r-l+1)/log(2);
	return val[rq[l][t]]>val[rq[r-(1<<t)+1][t]]?rq[l][t]:rq[r-(1<<t)+1][t];
}

void solve(int l,int r){
	if (l>r)return;
	int x=getrq(l,r);
	ans=(ans+1ll*val[x]*(x-l+1)%mo*(r-x+1)%mo)%mo;
	solve(l,x-1);
	solve(x+1,r);
}

int main(){
	n=get();k=get();
	fo(i,1,n)rmq[i][0]=a[i]=get();
	fo(j,1,log(n)/log(2))
		fo(i,1,n-(1<<j)+1)
		rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
	fo(r,1,k-1){
		m=0;
		for(int x=r;x+k-1<=n;x+=k-1)key[++m]=x;
		fo(i,1,m)val[i]=getmax(key[i],min(n,key[i]+k-1));
		fo(i,1,m)rq[i][0]=i;
		fo(j,1,log(m)/log(2))
			fo(i,1,m-(1<<j)+1)
			rq[i][j]=val[rq[i][j-1]]>val[rq[i+(1<<(j-1))][j-1]]?rq[i][j-1]:rq[i+(1<<(j-1))][j-1];
		solve(1,m);
	}
	cout<<ans<<endl;
	return 0;
}