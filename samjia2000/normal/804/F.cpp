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

const int L = 2e6+5;
const int N = 5005;
const int mo = 1e9+7;

int n,A,B;
bool mp[N][N];
char str[N];

int sta[N],tp;
bool pd[N];
int dfn[N],f[N],k;
int be[N],m;

void tarjan(int x){
	dfn[x]=f[x]=++k;
	pd[sta[++tp]=x]=1;
	fo(y,1,n)
	if (mp[x][y]){
		if (!dfn[y]){
			tarjan(y);
			f[x]=min(f[x],f[y]);
		}
		else if (pd[y])f[x]=min(f[x],dfn[y]);
	}
	if (f[x]==dfn[x]){
		m++;
		while(sta[tp+1]!=x){
			be[sta[tp]]=m;
			pd[sta[tp--]]=0;
		}
	}
}

int siz[N];
int St[N],Ed[N];
int Len;
int Real[L],Fake[L];
int d[N];
bool ins[N][N];
int num[N];

bool cmp(int x,int y){return d[x]<d[y];}

int key[N];
int sz[N],tr[N];

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

struct sstack{
	int st,len;
}st[20];
int top,tot;
int tv[L*4];

void merge(){
	tot=0;
	int u_=0;
	fo(i,1,top){
		if (i>1&&st[i].len==st[u_].len){
			fo(x,0,st[i].len-1)tv[st[u_].st+x]|=tv[st[i].st+x];
			continue;
		}
		u_++;
		st[u_].len=st[i].len;
		st[u_].st=tot+1;
		fo(x,0,st[i].len-1)tv[st[u_].st+x]=tv[st[i].st+x];
		tot+=st[i].len;
	}
	top=u_;
}

struct gang{
	int fake,real;
}a[N];

bool cmp1(gang a,gang b){return a.fake+a.real!=b.fake+b.real?a.fake+a.real<b.fake+b.real:a.real<b.real;}

LL js[N],inv[N];

LL calc(int n,int m){return n<m?0:js[n]*inv[m]%mo*inv[n-m]%mo;}

int main(){
	n=get();A=get();B=get();
	fo(i,1,n){
		scanf("%s",str+1);
		fo(j,1,n)mp[i][j]=(str[j]=='1');
	}
	fo(i,1,n){
		siz[i]=get();
		St[i]=Len+1;
		fo(j,1,siz[i]){
			char ch;
			while(ch=getchar(),ch<'0'||ch>'9');
			Real[++Len]=ch-'0';
		}
		Ed[i]=Len;
	}
	fo(i,1,n)
	if (!dfn[i])tarjan(i);
	fo(i,1,n)
		fo(j,1,n)
		if (mp[i][j]&&be[i]!=be[j]&&!ins[be[j]][be[i]]){
			ins[be[j]][be[i]]=1;
			d[be[j]]++;
		}
	fo(i,1,m)num[i]=i;
	sort(num+1,num+1+m,cmp);
	fo(i,1,m)tr[num[i]]=i;
	fo(i,1,n)be[i]=tr[be[i]];
	top=0;
	fo(id,1,m){
		k=0;
		fo(i,1,n)
		if (be[i]==id)key[++k]=i;
		sz[id]=siz[key[1]];
		fo(i,1,k)sz[id]=gcd(sz[id],siz[key[i]]);
		
		st[++top].st=tot+1;
		st[top].len=sz[id];
		fo(i,tot+1,tot+sz[id])tv[i]=0;
		fo(i,1,k)
			fo(j,St[key[i]],Ed[key[i]])
			tv[tot+1+(j-St[key[i]])%sz[id]]|=Real[j];
		tot+=sz[id];
		
		fo(u,1,top-1){
			int d=gcd(st[u].len,sz[id]);
			fo(x,0,d-1){
				for(int w=x;w<st[u].len;w+=d)tv[x+st[u].st]|=tv[w+st[u].st];
				for(int w=x;w<sz[id];w+=d)tv[st[top].st+w]|=tv[st[u].st+x];
			}
			st[u].len=d;
		}
		
		fo(i,1,k)
			fo(j,St[key[i]],Ed[key[i]])
			Fake[j]=tv[st[top].st+(j-St[key[i]])%sz[id]]^Real[j];
		
		merge();
	}
	fo(i,1,n){
		a[i].real=a[i].fake=0;
		fo(j,St[i],Ed[i])
		if (Real[j])a[i].real++;
		else if (Fake[j])a[i].fake++;
	}
	LL ans=0;
	sort(a+1,a+1+n,cmp1);
	js[0]=js[1]=1;
	fo(i,2,n)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,n)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,n)inv[i]=inv[i]*inv[i-1]%mo;
	fo(i,1,n){
		int p=0,q=0;
		fo(j,i+1,n)
		if (a[j].real>a[i].real+a[i].fake)p++;else q++;
		fo(x,max(0,p+B-A),min(p,B-1))ans=(ans+calc(q,B-1-x)*calc(p,x)%mo)%mo;
	}
	cout<<ans<<endl;
	return 0;
}