#include<bits/stdc++.h>

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

const int N = 1e5+5;

int n,pn;
int a[N];
int f[N],bit[N];

void add(int x,int v){for(;x<=pn;x+=x&-x)bit[x]=max(bit[x],v);}

int query(int x){int ret=0;for(;x;x-=x&-x)ret=max(ret,bit[x]);return ret;}

bool bz[N];

int m;
vector<int>key[N];

void solve(int n,int *a){
	if (!n)return;
	fo(i,1,pn)bit[i]=0;
	int mx=0;
	fo(i,1,n){
		bz[i]=0;
		f[i]=query(a[i]-1)+1;
		add(a[i],f[i]);
		mx=max(mx,f[i]);
	}
	int k=sqrt(n*2);
	while(k*(k+1)/2<n)k++;
	while(k*(k-1)/2>=n)k--;
	if (mx>=k){
		int v=pn+1,now=mx;
		m++;
		fd(i,n,1)
		if (f[i]==now&&a[i]<v){
			v=a[i];
			key[m].push_back(a[i]);
			now--;
			bz[i]=1;
		}
		reverse(key[m].begin(),key[m].end());
		int n_=0;
		fo(i,1,n)if (!bz[i])a[++n_]=a[i];
		n=n_;
		solve(n,a);
	}
	else{
		fo(i,1,n)key[m+f[i]].push_back(a[i]);
		m+=mx;
	}
}

void solve(){
	n=get();
	fo(i,1,n)a[i]=get();
	pn=n;
	m=0;
	fo(i,1,n)key[i].clear();
	solve(n,a);
	printf("%d\n",m);
	fo(i,1,m){
		printf("%d",key[i].size());
		for(auto x:key[i])printf(" %d",x);
		putchar('\n');
	}
}

int main(){
	for(int _=get();_;_--)solve();
	return 0;
}