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

const int MXL = 5000;
const int mo = 10007;
const db pi = acos(-1);
const int PL = 4096;

int N,len;
int bitr[MXL]; 
struct comp{
	db x,y;
	comp(const db x_=0,const db y_=0){x=x_;y=y_;}
};
comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
comp conj(comp a){return comp(a.x,-a.y);}
comp A[MXL],B[MXL];
db cs[MXL],si[MXL];

void prepare(){
	fo(i,0,N-1){
		bitr[i]=0;
		fo(j,0,len-1)
		if ((i&(1<<j))>0)bitr[i]^=(1<<(len-1-j));
	}
}

void DFT(comp *a){
	fo(i,0,N-1)if (i<bitr[i])swap(a[i],a[bitr[i]]);
	for(int now=2;now<=N;now<<=1){
		int half=now/2;
		fo(i,0,half-1){
			comp w=comp(cs[PL/now*i],si[PL/now*i]);
			for(int j=i;j<N;j+=now){
				comp l=a[j],r=a[j+half]*w;
				a[j+half]=l-r;
				a[j]=l+r;
			}
		}
	}
}

void IDFT(comp *a){
	fo(i,0,N-1)if (i<bitr[i])swap(a[i],a[bitr[i]]);
	for(int now=2;now<=N;now<<=1){
		int half=now/2;
		fo(i,0,half-1){
			comp w=comp(cs[PL/now*i],-si[PL/now*i]);
			for(int j=i;j<N;j+=now){
				comp l=a[j],r=a[j+half]*w;
				a[j+half]=l-r;
				a[j]=l+r;
			}
		}
	}
	fo(i,0,N-1){
		a[i].x=a[i].x/N;
		a[i].y=a[i].y/N;
	}
}

void fft(LL *a,LL *b,LL *tmp){
	if (N<=32){
		fo(i,0,N-1)tmp[i]=0;
		fo(i,0,N-1)
		if (a[i])
			fo(j,0,N-i-1)
			if (b[j])tmp[i+j]=(tmp[i+j]+a[i]*b[j]);
		fo(i,0,N-1)tmp[i]=tmp[i]%mo;
		return;
	}
	fo(i,0,N-1)A[i]=comp(a[i],b[i]);
	DFT(A);
	fo(i,0,N-1){
		comp x=A[i],y=A[i==0?0:N-i];
		comp va=(x+conj(y))*comp(0.5,0),vb=(x-conj(y))*comp(0,-0.5);
		B[i]=va*vb;
	}
	IDFT(B);
	fo(i,0,N-1){
		LL v=B[i].x+0.3;
		tmp[i]=v%mo;
	}
}

void fft(int n,LL *a,int m,LL *b,LL *tmp){
	int qn=N;
	N=1,len=0;
	while(N<=n+m)N<<=1,len++;
	if (N!=qn)prepare();
	if (n*m<=N*len){
		fo(i,0,n+m){
			tmp[i]=0;
			fo(j,max(0,i-m),n)tmp[i]=(tmp[i]+a[j]*b[i-j]);
			tmp[i]=tmp[i]%mo;
		}
		return;
	}
	fo(i,n+1,N-1)a[i]=0;
	fo(i,m+1,N-1)b[i]=0;
	fft(a,b,tmp);
}

const int MAXN = 805;

char s[MAXN];
int n;
int f[405][405][405];
LL L;
int k;

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x>=y?x-y:x+mo-y;}

int trs0[805][805],trs1[805][805];

LL s0[MAXN*2],s1[MAXN*2],s2[MAXN*4];
LL js[MAXN*2],inv[MAXN*2],mi24[MAXN*2],mi25[MAXN*2];

LL quickmi(LL x,LL tim){LL ans=1;for(;tim;tim/=2,x=x*x%mo)if (tim&1)ans=ans*x%mo;return ans;}

LL calc(int n,int m){return js[n]*inv[m]%mo*inv[n-m]%mo;}

LL a[MAXN*2],Mo[MAXN*2];
LL mi[MAXN*2],pdt[MAXN*2];
int m;

LL res[MAXN*2],dv[MAXN*2];
LL ny[MAXN*2],q0[MAXN*2];
LL tmp[MAXN*4];

void Mod(){
	int A=0,B=m;
	fd(i,B*2-2,0)if (tmp[i]){A=i;break;}
	if (A<B){fo(i,0,B-1)res[i]=tmp[i];return;}
	if (A-B<=30){
		fd(i,A,B)
		if (tmp[i]){
			LL s=tmp[i];
			fo(x,0,B)tmp[i-B+x]=dec(tmp[i-B+x],Mo[x]*s%mo);
		}
		fo(i,0,B-1)res[i]=tmp[i];
		return;
	}
	fo(i,0,A-B)s0[i]=tmp[A-i],s1[i]=ny[i];
	fft(A-B,s0,A-B,s1,dv);
	reverse(dv,dv+A-B+1);
	fo(i,0,B)s0[i]=Mo[i];
	fo(i,0,A-B)s1[i]=dv[i];
	fft(B,s0,A-B,s1,dv);
	fo(i,0,B-1)res[i]=dec(tmp[i],dv[i]);
}

void multi(LL *a,LL *b,LL *c){
	fft(m-1,a,m-1,b,tmp);
	Mod();
	fo(i,0,m-1)c[i]=res[i];
}

int main(){
	fo(i,0,PL-1)cs[i]=cos(pi*2/PL*i),si[i]=sin(pi*2/PL*i);
	scanf("%s",s+1);
	n=strlen(s+1);
	js[0]=js[1]=inv[0]=inv[1]=1;
	fo(i,2,n*4)js[i]=js[i-1]*i%mo;
	fo(i,2,n*4)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	fo(i,2,n*4)inv[i]=inv[i]*inv[i-1]%mo;
	mi24[0]=mi25[0]=1;
	fo(i,1,n*4)mi24[i]=mi24[i-1]*24%mo,mi25[i]=mi25[i-1]*25%mo;
	scanf("%I64d",&L);
	L=L+n;
	f[1][n][0]=1;
	fo(i,1,n)
		fd(j,n,i)
			fo(k,0,min(i-1,n-j))
			if (f[i][j][k]){
				if (s[i]==s[j])f[i+1][j-1][k+1]=add(f[i+1][j-1][k+1],f[i][j][k]);
				else{
					f[i+1][j][k]=add(f[i+1][j][k],f[i][j][k]);
					f[i][j-1][k]=add(f[i][j-1][k],f[i][j][k]);
				}
			}
	fo(i,1,n+1)
		fo(j,0,i-1)
			fo(k,0,min(i-1,n-j))
			if (f[i][j][k]){
				int A=k,B=i-1+n-j-k*2;
				trs0[B][A]=add(trs0[B][A],f[i][j][k]);
			}
	if (L%2==0){
		int ans=0;
		fo(l,0,2*n)
			fo(i,max(0,l-n),min(l,n)){
				int j=l-i;
				if (trs0[i][j]){
					m=i+j+1;
					fo(x,0,m)s0[x]=s1[x]=0;
					if (!i)s0[0]=1;
					else fo(x,0,i)s0[x]=(x&1)?mo-mi24[x]*calc(i,x)%mo:mi24[x]*calc(i,x)%mo;
					if (!j)s1[0]=1;
					else fo(x,0,j)s1[x]=(x&1)?mo-mi25[x]*calc(j,x)%mo:mi25[x]*calc(j,x)%mo;
					fd(x,j+1,1)s1[x]=(s1[x]+mo-1ll*s1[x-1]*26%mo)%mo;
					fft(i,s0,j+1,s1,s2);
					LL iv=quickmi(s2[m],mo-2);
					fo(x,0,m)Mo[x]=s2[m-x];
					
					fo(x,0,m)s0[x]=s1[x]=0;
					if (!i)s0[0]=1;
					else fo(x,0,m)s0[x]=mi24[x]*calc(x+i-1,i-1)%mo;
					if (!j)s1[0]=1;
					else fo(x,0,m)s1[x]=mi25[x]*calc(x+j-1,j-1)%mo;
					fo(x,1,m)s1[x]=add(s1[x],1ll*s1[x-1]*26%mo);
					fft(m,s0,m,s1,s2);
					fo(x,0,m-1)ny[x]=a[x]=s2[x];
					
					LL tim=L/2-i-j;
					if (tim<0)continue;
					fo(x,0,m)pdt[x]=mi[x]=0;
					mi[1]=1;pdt[0]=1;
					for(;tim;tim/=2,multi(mi,mi,mi))
					if (tim&1)multi(pdt,mi,pdt);
					LL sum=0;
					fo(x,0,m-1)sum=(sum+1ll*pdt[x]*a[x])%mo;
					ans=(ans+sum*trs0[i][j])%mo;
				}
			}
		printf("%d\n",ans);
	}
	else{
		int ans=0;
		fo(i,0,n)fo(j,0,n)trs1[i][j]=0;
		fo(i,1,n)
			fo(k,0,min(i-1,n-i))
			if (f[i][i][k]){
				int A=k,B=i-1+n-i-k*2;
				trs1[B][A+1]=add(trs1[B][A+1],f[i][i][k]);
			}
		fo(l,0,2*n)
			fo(i,max(0,l-n),min(l,n)){
				int j=l-i;
				if (trs0[i][j]||trs1[i][j]){
					if (L/2-i-j<0){
						m=i+j;
						fo(x,0,m)s0[x]=s1[x]=0;
						if (!i)s0[0]=1;
						else fo(x,0,i)s0[x]=(x&1)?mo-mi24[x]*calc(i,x)%mo:mi24[x]*calc(i,x)%mo;
						if (!j)s1[0]=1;
						else fo(x,0,j)s1[x]=(x&1)?mo-mi25[x]*calc(j,x)%mo:mi25[x]*calc(j,x)%mo;
						fft(i,s0,j,s1,s2);
						LL iv=quickmi(s2[m],mo-2);
						fo(x,0,m)Mo[x]=s2[m-x];
						
						fo(x,0,m)s0[x]=s1[x]=0;
						if (!i)s0[0]=1;
						else fo(x,0,m)s0[x]=mi24[x]*calc(x+i-1,i-1)%mo;
						if (!j)s1[0]=1;
						else fo(x,0,m)s1[x]=mi25[x]*calc(x+j-1,j-1)%mo;
						fft(m,s0,m,s1,s2);
						fo(x,0,m-1)ny[x]=a[x]=s2[x];
						
						LL v0=trs1[i][j];
						fd(x,m-1,0)a[x]=(a[x]*v0%mo)%mo;
					}
					else{
						m=i+j+1;
						fo(x,0,m)s0[x]=s1[x]=0;
						if (!i)s0[0]=1;
						else fo(x,0,i)s0[x]=(x&1)?mo-mi24[x]*calc(i,x)%mo:mi24[x]*calc(i,x)%mo;
						if (!j)s1[0]=1;
						else fo(x,0,j)s1[x]=(x&1)?mo-mi25[x]*calc(j,x)%mo:mi25[x]*calc(j,x)%mo;
						fd(x,j+1,1)s1[x]=(s1[x]+mo-1ll*s1[x-1]*26%mo)%mo;
						fft(i,s0,j+1,s1,s2);
						LL iv=quickmi(s2[m],mo-2);
						fo(x,0,m)Mo[x]=s2[m-x];
						
						fo(x,0,m)s0[x]=s1[x]=0;
						if (!i)s0[0]=1;
						else fo(x,0,m)s0[x]=mi24[x]*calc(x+i-1,i-1)%mo;
						if (!j)s1[0]=1;
						else fo(x,0,m)s1[x]=mi25[x]*calc(x+j-1,j-1)%mo;
						fo(x,1,m)s1[x]=add(s1[x],1ll*s1[x-1]*26%mo);
						fft(m,s0,m,s1,s2);
						fo(x,0,m-1)ny[x]=a[x]=s2[x];
						
						LL v0=trs1[i][j],v1=26ll*(trs0[i][j]+mo-trs1[i][j])%mo;
						fd(x,m-1,1)a[x]=(a[x]*v0%mo+a[x-1]*v1%mo)%mo;
						a[0]=a[0]*v0%mo;
					}
					
					LL tim=L/2-i-j+1;
					if (tim<0)continue;
					fo(x,0,m)pdt[x]=mi[x]=0;
					mi[1]=1;pdt[0]=1;
					for(;tim;tim/=2,multi(mi,mi,mi)){
						if (tim&1)multi(pdt,mi,pdt);
					}
					LL sum=0;
					fo(x,0,m-1)sum=(sum+1ll*pdt[x]*a[x])%mo;
					ans=(ans+sum)%mo;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}