#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

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

const int MAXN = (1<<18)+5;
const int maxn = (1<<18);
const int mo = 998244353;
const int B = (1<<15)-1;
const db pi = acos(-1);

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}
LL quickmi(LL x,LL tim){
	LL ret=1;
	for(;tim;tim/=2,x=x*x%mo)
	if(tim&1)ret=ret*x%mo;
	return ret;
}
LL js[MAXN],inv[MAXN];

void prepare(){
	js[0]=js[1]=1;
	fo(i,2,maxn)js[i]=js[i-1]*i%mo;
	inv[0]=inv[1]=1;
	fo(i,2,maxn)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,maxn)inv[i]=inv[i]*inv[i-1]%mo;
}

namespace FFT{
	struct comp{
		//x+yi
		db x,y;
		comp(const db x_=0,const db y_=0){x=x_;y=y_;}
	}A[MAXN],B[MAXN],C[MAXN],D[MAXN];
	comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
	comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
	comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
	comp conj(comp a){return comp(a.x,-a.y);}
	int N;
	db cs[MAXN],si[MAXN];
	
	void prepare(){
		fo(i,0,maxn){
			cs[i]=cos(pi*2/maxn*i);
			si[i]=sin(pi*2/maxn*i);
		}
	}
	
	void DFT(comp *a){
		for(int i=0,j=0;i<N;i++){
			if (i<j)swap(a[i],a[j]);
			int x=N>>1;
			for(;(j^x)<j;x>>=1)j^=x;
			j^=x;
		}
		for(int i=1,d=1;i<N;i<<=1,d++)
			for(int j=0;j<N;j+=(i<<1))
				for(int k=0;k<i;k++){
					comp l=a[j+k],r=a[i+j+k]*comp(cs[(maxn>>d)*k],si[(maxn>>d)*k]);
					a[i+j+k]=l-r;
					a[j+k]=l+r;
				}
	}
	
	void IDFT(comp *a){
		DFT(a);
		reverse(a+1,a+N);
		fo(i,0,N-1)a[i].x/=N,a[i].y/=N;
	}
	
	void multi(LL *a,LL *b,LL *c,int n,int m){
		fo(i,0,N-1)A[i]=B[i]=comp(0,0);
		fo(i,0,n)A[i]=comp(a[i]>>15,a[i]&32767);
		fo(i,0,m)B[i]=comp(b[i]>>15,b[i]&32767);
		DFT(A),DFT(B);
		fo(i,0,N-1){
			comp x=A[i],y=A[i==0?0:N-i];
			comp a0=(x+conj(y))*comp(0.5,0),a1=(x-conj(y))*comp(0,-0.5);
			x=B[i],y=B[i==0?0:N-i];
			comp b0=(x+conj(y))*comp(0.5,0),b1=(x-conj(y))*comp(0,-0.5);
			C[i]=a0*b0+comp(0,1)*a0*b1;
			D[i]=a1*b0+comp(0,1)*a1*b1;
		}
		IDFT(C),IDFT(D);
		fo(i,0,n+m){
			LL v0=C[i].x+0.3,v1=C[i].y+0.3,v2=D[i].x+0.3,v3=D[i].y+0.3;
			v0=((v0%mo)*1073741824)%mo;
			v1=((v1%mo)*32768)%mo;
			v2=((v2%mo)*32768)%mo;
			v3=v3%mo;
			c[i]=add(v0,add(v1,add(v2,v3)));
		}
	}
	
}
int n,k;
struct edge{
	int x,nxt;
}e[MAXN];
int h[MAXN],tot;
bool vis[MAXN];
int siz[MAXN];

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}
int fa[MAXN];

void dfs(int x){
	vis[x]=1;
	siz[x]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (!vis[e[p].x]){
		fa[e[p].x]=x;
		dfs(e[p].x);
		siz[x]+=siz[e[p].x];
	}
}

struct keypoint{
	int st,len;
}sec[MAXN];
int u;
int len;
LL poly[MAXN],val[MAXN],tmp[MAXN];
int key[MAXN];
LL tmpa[MAXN],tmpb[MAXN];

void solve_poly(){
	for(FFT::N=2;u>1;FFT::N<<=1){
		int u_=0;
		for(int i=1;i<=u;){
			int j=i+1;
			for(;j<=u&&sec[i].len+sec[j].len<FFT::N;j++){
				fo(x,1,sec[i].len)tmpa[x]=poly[sec[i].st+x-1];
				fo(x,1,sec[j].len)tmpb[x]=poly[sec[j].st+x-1];
				tmpa[0]=tmpb[0]=1;
				FFT::multi(tmpa,tmpb,tmp,sec[i].len,sec[j].len);
				sec[i].len+=sec[j].len;
				fo(x,1,sec[i].len)poly[sec[i].st+x-1]=tmp[x];
			}
			sec[++u_]=sec[i];
			i=j;
		}
		u=u_;
	}
}

LL sum[MAXN];

LL f[MAXN],g[MAXN],vf[MAXN],vg[MAXN];
LL ans;

void dfs2(int x){
	vf[x]=f[x];
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x]==x){
		int y=e[p].x;
		dfs2(y);
		vf[x]=add(vf[x],vf[y]);
	}
}

void dfs3(int x){
	ans=add(ans,f[x]*vg[x]%mo);
	LL pre=vg[x];
	for(int p=h[x];p;p=e[p].nxt)
	if (fa[e[p].x]==x){
		int y=e[p].x;
		vg[y]=add(pre,g[y]);
		dfs3(y);
		pre=add(pre,vf[y]);
	}
}

int main(){
	n=get();k=get();
	if (k==1)return printf("%I64d\n",1ll*n*(n-1)/2%mo),0;
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
	}
	prepare();
	FFT::prepare();
	dfs(1);
	fo(st,1,n){
		u=len=0;
		if (siz[st]<n){
			poly[len=1]=n-siz[st];
			sec[++u].st=1;
			sec[u].len=1;
			key[u]=n-siz[st];
		}
		for(int p=h[st];p;p=e[p].nxt)
		if(siz[st]>siz[e[p].x]){
			key[++u]=poly[++len]=siz[e[p].x];
			sec[u].st=len;
			sec[u].len=1;
		}
		int pu=u;
		solve_poly();
		u=pu;
		sort(key+1,key+1+u);
		int u_=1;
		fo(i,2,u)if (key[i]>key[i-1])key[++u_]=key[i];
		u=u_;
		poly[0]=1;
		fo(i,1,u){
			int v=key[i];
			tmp[0]=1;
			fo(x,1,len)tmp[x]=dec(poly[x],tmp[x-1]*v%mo);
			val[v]=0;
			fo(x,0,min(k,len-1))val[v]=(val[v]+tmp[x]*inv[k-x])%mo;
			val[v]=val[v]*js[k]%mo;
		}
		if (siz[st]<n)f[st]=val[n-siz[st]];
		for(int p=h[st];p;p=e[p].nxt)
		if (siz[st]>siz[e[p].x])g[e[p].x]=val[siz[e[p].x]];
		fo(i,0,len)poly[i]=0;
	}
	dfs2(1);
	dfs3(1);
	cout<<ans<<endl;
	return 0;
}