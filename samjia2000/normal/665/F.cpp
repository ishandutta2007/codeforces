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

const int MAXN = 1e6;
const int L = 8.1e7;
const int U = 4;

bool bz[MAXN+5];
int pri[MAXN],k;
int pre[MAXN+5];

void prepare(){
	bz[1]=1;
	fo(i,2,MAXN){
		if (!bz[i])pre[i]=1,pri[++k]=i;
		fo(j,1,k){
			if (1ll*i*pri[j]>MAXN)break;
			bz[i*pri[j]]=1;
			if (i%pri[j]==0)break;
		}
	}
	fo(i,2,MAXN)pre[i]+=pre[i-1];
}

LL n,pren;
LL key[MAXN];
int m;
int st[MAXN];
LL f[MAXN];
LL val[MAXN],ans[MAXN];
LL lim;
int w1[MAXN];
LL pv[MAXN];

int getw(LL v){if (v<=lim)return v;return w1[n/v];}

int main(){
	prepare();
	cin>>n;
	pren=n;
	m=0;
	lim=sqrt(n);
	fo(i,1,lim)key[++m]=i;
	if (n/lim!=lim){
		key[++m]=n/lim;
		w1[lim]=m;
	}
	fd(i,lim-1,1){
		key[++m]=n/i;
		w1[i]=m;
	}
	int w=1;
	fo(i,1,k){
		while(w<=m&&1ll*pri[i]*pri[i]>key[w])w++;
		st[i]=w;
	}
	fo(i,1,m)f[i]=key[i]-1;
	st[0]=1;
	fo(d,1,k){
		fo(i,st[d-1],st[d]-1)ans[i]=f[i];
		int nw=st[d];
		fo(i,st[d],m){
			LL delt=0;
			while(nw<m&&key[nw+1]*pri[d]<=key[i])nw++;
			if (key[i]<key[st[d]]*pri[d])delt=delt+2+ans[getw(key[i]/pri[d])]-d;
			else delt=pv[nw]+1+(f[nw]-d);
			pv[i]=delt;
			f[i]=f[i]+1-delt;
		}
	}
	LL ret=0;
	for(LL now=2;now*now*now<=n;now++)if (!bz[now])ret++;
	int pv=0;
	fo(i,2,lim)
	if (!bz[i]){
		pv++;
		ret=ret+ans[getw(n/i)]-pv;
	}
	cout<<ret<<endl;
	return 0;
}