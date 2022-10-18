#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
//#define MTT
#define normal
namespace NTT// NTT
{
	typedef unsigned int ui;
	typedef unsigned long long ll;
	const int N=1<<21;
	const ui p=998244353;
	const ui g=3,f=1u<<31,I=86'583'718;//g^((p-1)/4)
#ifdef MTT
	const ui p1=469'762'049,p2=998'244'353,p3=1'004'535'809;// 3
	const ui inv_p1=554'580'198,inv_p12=395'249'030;//1  2 1*2  3 1*2 mod 3
	ui w1[N],w2[N],w3[N];//
#endif
	ui w[N],r[N],preone=3;
	ui inv[N],preinv=0,W;//W for mosqrt
	ui ksm(ui x,ui y)
	{
		ui r=1;
		while (y)
		{
			if (y&1) r=(ll)r*x%p;
			x=(ll)x*x%p;
			y>>=1;
		}
		return r;
	}
#ifdef MTT
	ui ksm1(ui x,ui y)
	{
		ui r=1;
		while (y)
		{
			if (y&1) r=(ll)r*x%p1;
			x=(ll)x*x%p1;
			y>>=1;
		}
		return r;
	}
	ui ksm2(ui x,ui y)
	{
		ui r=1;
		while (y)
		{
			if (y&1) r=(ll)r*x%p2;
			x=(ll)x*x%p2;
			y>>=1;
		}
		return r;
	}
	ui ksm3(ui x,ui y)
	{
		ui r=1;
		while (y)
		{
			if (y&1) r=(ll)r*x%p3;
			x=(ll)x*x%p3;
			y>>=1;
		}
		return r;
	}
#endif
	struct P
	{
		ui x,y;
		P(ui a=0,ui b=0):x(a),y(b){}
		P operator*(P &a)
		{
			return P(((ll)x*a.x+(ll)y*a.y%p*W)%p,((ll)x*a.y+(ll)y*a.x)%p);
		}
	};
	ui ksm(P x,ui y)
	{
		P r(1,0);
		while (y)
		{
			if (y&1) r=r*x;
			x=x*x;y>>=1;
		}
		return r.x;
	}
	ui mosqrt(ui x)
	{
		if (x==0) return 0;
		if (ksm(x,p-1>>1)!=1) {puts("-1");exit(0);}
		ui y;
		do y=rnd()%p; while (ksm(W=((ll)y*y%p+p-x)%p,p-1>>1)<=1);//not for p=2
		y=ksm(P(y,1),p+1>>1);
		return y*2<p?y:p-y;
	}
#ifdef MTT
	void init(ui n)
	{
		if (preone==n) return;
		ui b=__builtin_ctz(n)-1,i,j,k,l,wn;
		for (i=1;i<n;i++) r[i]=r[i>>1]>>1|(i&1)<<b;++b;
		for (j=1,k=1;j<n;j=l,k++)
		{
			l=j<<1;
			wn=ksm1(g,p1-1>>k);
			w1[j]=1;
			for (i=j+1;i<l;i++) w1[i]=(ll)w1[i-1]*wn%p1;
		}
		for (j=1,k=1;j<n;j=l,k++)
		{
			l=j<<1;
			wn=ksm2(g,p2-1>>k);
			w2[j]=1;
			for (i=j+1;i<l;i++) w2[i]=(ll)w2[i-1]*wn%p2;
		}
		for (j=1,k=1;j<n;j=l,k++)
		{
			l=j<<1;
			wn=ksm3(g,p3-1>>k);
			w3[j]=1;
			for (i=j+1;i<l;i++) w3[i]=(ll)w3[i-1]*wn%p3;
		}
		preone=n;
	}
#else
	void init(ui n)
	{
		if (preone==n) return;
		ui b=__builtin_ctz(n)-1,i,j,k,l,wn;
		for (i=1;i<n;i++) r[i]=r[i>>1]>>1|(i&1)<<b;++b;
		for (j=1,k=1;j<n;j=l,k++)
		{
			l=j<<1;
			wn=ksm(g,p-1>>k);
			w[j]=1;
			for (i=j+1;i<l;i++) w[i]=(ll)w[i-1]*wn%p;
		}
		preone=n;
	}
#endif
	ui cal(ui x) {return 1u<<32-__builtin_clz(max(x,2u)-1);}
	void getinv(int n)
	{
		if (!preinv) preinv=inv[1]=1;
		if (n<=preinv) return;
		for (ui i=preinv+1,j;i<=n;i++)
		{
			j=p/i;
			inv[i]=(ll)(p-j)*inv[p-i*j]%p;
		}
		preinv=n;
	}
	struct Q
	{
		vector<ui> a;
		Q(ui x=2)
		{
			x=cal(x);
			a.resize(x);
			for (ui i=0;i<x;i++) a[i]=0;
		}
	#ifdef MTT
		void dft1(int o=0)
		{
			ui n=a.size(),i,j,k,x,y,*f,*g,*wn,*A=a.data();
			for (i=1;i<n;i++) if (i<r[i]) swap(A[i],A[r[i]]);
			for (k=1;k<n;k<<=1)
			{
				wn=w1+k;
				for (i=0;i<n;i+=k<<1) 
				{
					f=A+i;g=A+i+k;
					for (j=0;j<k;j++)
					{
						x=f[j];y=(ll)g[j]*wn[j]%p1;
						if (x+y>=p1) f[j]=x+y-p1; else f[j]=x+y;
						if (x<y) g[j]=x-y+p1; else g[j]=x-y;
					}
				}
			}
			if (o)
			{
				x=ksm1(n,p1-2);
				for (i=0;i<n;i++) A[i]=(ll)A[i]*x%p1;
				reverse(A+1,A+n);
			}
		}
		void dft2(int o=0)
		{
			ui n=a.size(),i,j,k,x,y,*f,*g,*wn,*A=a.data();
			for (i=1;i<n;i++) if (i<r[i]) swap(A[i],A[r[i]]);
			for (k=1;k<n;k<<=1)
			{
				wn=w2+k;
				for (i=0;i<n;i+=k<<1) 
				{
					f=A+i;g=A+i+k;
					for (j=0;j<k;j++)
					{
						x=f[j];y=(ll)g[j]*wn[j]%p2;
						if (x+y>=p2) f[j]=x+y-p2; else f[j]=x+y;
						if (x<y) g[j]=x-y+p2; else g[j]=x-y;
					}
				}
			}
			if (o)
			{
				x=ksm2(n,p2-2);
				for (i=0;i<n;i++) A[i]=(ll)A[i]*x%p2;
				reverse(A+1,A+n);
			}
		}
		void dft3(int o=0)
		{
			ui n=a.size(),i,j,k,x,y,*f,*g,*wn,*A=a.data();
			for (i=1;i<n;i++) if (i<r[i]) swap(A[i],A[r[i]]);
			for (k=1;k<n;k<<=1)
			{
				wn=w3+k;
				for (i=0;i<n;i+=k<<1) 
				{
					f=A+i;g=A+i+k;
					for (j=0;j<k;j++)
					{
						x=f[j];y=(ll)g[j]*wn[j]%p3;
						if (x+y>=p3) f[j]=x+y-p3; else f[j]=x+y;
						if (x<y) g[j]=x-y+p3; else g[j]=x-y;
					}
				}
			}
			if (o)
			{
				x=ksm3(n,p3-2);
				for (i=0;i<n;i++) A[i]=(ll)A[i]*x%p3;
				reverse(A+1,A+n);
			}
		}
	#else
		void dft(int o=0)
		{
			ui n=a.size(),i,j,k,x,y,*f,*g,*wn,*A=a.data();
			for (i=1;i<n;i++) if (i<r[i]) swap(A[i],A[r[i]]);
			for (k=1;k<n;k<<=1)
			{
				wn=w+k;
				for (i=0;i<n;i+=k<<1) 
				{
					f=A+i;g=A+i+k;
					for (j=0;j<k;j++)
					{
						x=f[j];y=(ll)g[j]*wn[j]%p;
						if (x+y>=p) f[j]=x+y-p; else f[j]=x+y;
						if (x<y) g[j]=x-y+p; else g[j]=x-y;
					}
				}
			}
			if (o)
			{
				getinv(n);x=inv[n];
				for (i=0;i<n;i++) A[i]=(ll)A[i]*x%p;
				reverse(A+1,A+n);
			}
		}
	#endif
		Q dao()
		{
			ui n=a.size();
			Q r(n);
			for (ui i=1;i<n;i++) r.a[i-1]=(ll)a[i]*i%p;
			return r;
		}
		Q ji()
		{
			ui n=a.size();
			getinv(n-1);
			Q r(n);
			for (ui i=1;i<n;i++) r.a[i]=(ll)a[i-1]*inv[i]%p; 
			return r;
		}
		Q operator-() const {Q r=(*this);ui n=a.size();for (ui i=0;i<n;i++) if (r.a[i]) r.a[i]=p-r.a[i];return r;}
		Q operator+(ui x) const {Q r=(*this);r+=x;return r;}
		void operator+=(ui x) {if ((a[0]+=x)>=p) a[0]-=p;}
		Q operator-(ui x) const {Q r=(*this);r-=x;return r;}
		void operator-=(ui x) {if (a[0]<x) a[0]=a[0]+p-x; else a[0]-=x;}
		Q operator*(ui k) const {Q r=(*this);r*=k;return r;}
		void operator*=(ui k) {ui n=a.size();for (ui i=0;i<n;i++) a[i]=(ll)a[i]*k%p;}
		Q operator+(Q f) const {f+=(*this);return f;}
		void operator+=(const Q &f) {ui n=f.a.size();if (a.size()<n) a.resize(n);for (ui i=0;i<n;i++) if ((a[i]+=f.a[i])>=p) a[i]-=p;}
		Q operator-(Q f) const {Q r=(*this);r-=f;return r;}
		void operator-=(const Q &f) {ui n=f.a.size();if (a.size()<n) a.resize(n);for (ui i=0;i<n;i++) if (a[i]<f.a[i]) a[i]+=p-f.a[i]; else a[i]-=f.a[i];}
		Q operator*(Q f) const {f*=(*this);return f;}
#ifdef normal
	#ifdef MTT
		void operator*=(Q g3)
		{
			cout<<"I didn't check it"<<endl;
			ui n=cal(a.size()+g3.a.size()-1),i;
			Q f,g1,g2;
			g1=g2=g3;
			init(n);
			ll x;
			a.resize(n);g1.a.resize(n);g2.a.resize(n);g3.a.resize(n);
			g1.dft1();g2.dft2();g3.dft3();
			f=*this;f.dft1();for (i=0;i<n;i++) g1.a[i]=(ll)g1.a[i]*f.a[i]%p1;g1.dft1(1);
			f=*this;f.dft2();for (i=0;i<n;i++) g2.a[i]=(ll)g2.a[i]*f.a[i]%p2;g2.dft2(1);
			f=*this;f.dft3();for (i=0;i<n;i++) g3.a[i]=(ll)g3.a[i]*f.a[i]%p3;g3.dft3(1);
			a.resize(n>>=1);ui _p12=(ll)p1*p2%p;
			for (i=0;i<n;i++)
			{
				x=(ll)(g2.a[i]+p2-g1.a[i])*inv_p1%p2*p1+g1.a[i];
				a[i]=((x+p3-g3.a[i])%p3*(p3-inv_p12)%p3*_p12+x)%p;
			}
			for (i=n-1;i>=2;i--) if (a[i]) break;
			a.resize(cal(i+1));
		}
	#else
		void operator*=(Q f)
		{
			ui n=cal(a.size()+f.a.size()-1);
			a.resize(n);f.a.resize(n);
			init(n);
			(*this).dft();f.dft();
			for (ui i=0;i<n;i++) a[i]=(ll)a[i]*f.a[i]%p;
			(*this).dft(1);
			ui i;
			for (i=n-1;i>=2;i--) if (a[i]) break;
			a.resize(cal(i+1));
		}
	#endif
#else
	#ifdef MTT
		void operator*=(Q g3)
		{
			Q f,g1,g2;
			g1=g2=g3;
			assert(a.size()==g3.a.size());
			ui n=a.size()<<1,i;init(n);
			ll x;
			a.resize(n);g1.a.resize(n);g2.a.resize(n);g3.a.resize(n);
			g1.dft1();g2.dft2();g3.dft3();
			f=*this;f.dft1();for (i=0;i<n;i++) g1.a[i]=(ll)g1.a[i]*f.a[i]%p1;g1.dft1(1);
			f=*this;f.dft2();for (i=0;i<n;i++) g2.a[i]=(ll)g2.a[i]*f.a[i]%p2;g2.dft2(1);
			f=*this;f.dft3();for (i=0;i<n;i++) g3.a[i]=(ll)g3.a[i]*f.a[i]%p3;g3.dft3(1);
			a.resize(n>>=1);ui _p12=(ll)p1*p2%p;
			for (i=0;i<n;i++)
			{
				x=(ll)(g2.a[i]+p2-g1.a[i])*inv_p1%p2*p1+g1.a[i];
				a[i]=((x+p3-g3.a[i])%p3*(p3-inv_p12)%p3*_p12+x)%p;
			}
		}// OJ 5e5 0.9s
	#else
		void operator*=(Q f)
		{
			assert(a.size()==f.a.size());
			ui n=a.size()<<1;
			init(n);
			a.resize(n);f.a.resize(n);
			(*this).dft();f.dft();
			for (ui i=0;i<n;i++) a[i]=(ll)a[i]*f.a[i]%p;
			(*this).dft(1);a.resize(n>>1);
		}
	#endif
#endif
	#ifdef MTT
		Q operator~()
		{
			Q q=(*this),r(2);
			ui n=a.size()<<1,i,j,k;a.resize(n);
			r.a[0]=ksm(a[0],p-2);
			for (j=2;j<=n;j<<=1)
			{
				init(j);k=j>>1;
				r.a.resize(j);
				q.a.resize(j);
				for (i=0;i<k;i++) q.a[i]=a[i];
				r=-(q*r-2)*r;
				r.a.resize(k);
			}
			n>>=1;
			a.resize(n);
			return r;
		}//trivial
	#else
		Q operator~()
		{
			Q q=(*this),r(2),g(2);
			ui n=a.size(),i,j,k;
			r.a[0]=ksm(a[0],p-2);
			for (j=2;j<=n;j<<=1)
			{
				init(j);
				k=j>>1;
				r.a.resize(j);
				g=r;
				q.a.resize(j);
				init(j);
				for (i=0;i<j;i++) q.a[i]=a[i];
				r.dft();q.dft();
				for (i=0;i<j;i++) q.a[i]=(ll)q.a[i]*r.a[i]%p;
				q.dft(1);
				for (i=0;i<k;i++) q.a[i]=0;
				q.dft();
				for (i=0;i<j;i++) r.a[i]=(ll)q.a[i]*r.a[i]%p;
				r.dft(1);
				for (i=0;i<k;i++) r.a[i]=g.a[i];
				for (i=k;i<j;i++) if (r.a[i]) r.a[i]=p-r.a[i];
			}
			return r;
		}
	#endif
		Q operator/(Q f) const {return (*this)*~f;}
		void operator/=(Q f) {f=~f;(*this)*=f;}
	};
#ifndef MTT
	Q sqr(Q b)
	{
		ui n=b.a.size()<<1,i;
		init(n);b.a.resize(n);
		b.dft();
		for (i=0;i<n;i++) b.a[i]=(ll)b.a[i]*b.a[i]%p;
		b.dft(1);
		b.a.resize(n>>1);
		return b;
	}
	vector<Q> cd;
	void cdq(Q &f,Q &g,ui l,ui r)//g_0=1,i*g_i=g_{i-j}*f_j,use for exp_cdq
	{
		ui i,m=l+r>>1,n=r-l,nn=n>>1;
		if (l==0&&r==f.a.size())
		{
			getinv(n-1);
			g.a.resize(n);
			for (i=0;i<n;i++) g.a[i]=0;
			cd.clear();cd.reserve(__builtin_ctz(n));
			Q a(2);
			for (i=2;i<=n;i<<=1)
			{
				a.a.resize(i);
				for (ui j=0;j<i;j++) a.a[j]=f.a[j];
				init(i);
				a.dft();cd.push_back(a);
			}
		}
		if (l+1==r)
		{
			if (l==0) g.a[l]=1; else g.a[l]=(ll)g.a[l]*inv[l]%p;
			return;
		}
		cdq(f,g,l,m);
		Q a=cd[__builtin_ctz(n)-1],b(n);
		for (i=0;i<nn;i++) b.a[i]=g.a[l+i];
		init(n);b.dft();
		for (i=0;i<n;i++) a.a[i]=(ll)a.a[i]*b.a[i]%p;
		a.dft(1);
		for (i=m;i<r;i++) if ((g.a[i]+=a.a[i-l])>=p) g.a[i]-=p;
		cdq(f,g,m,r);
	}
	Q exp_cdq(Q f)
	{
		Q g(2);ui n=f.a.size();
		for (ui i=1;i<n;i++) f.a[i]=(ll)f.a[i]*i%p;
		cdq(f,g,0,n);
		return g;
	}
	Q sqrt(Q b)
	{
		Q q(2),f(2),r(2);
		ui n=b.a.size();
		int i,j=n,l;
		for (i=0;i<n;i++) if (b.a[i]) {j=i;break;}
		if (j==n) return b;
		if (j&1) {puts("-1");exit(0);}l=j>>1;
		for (i=0;i<n-j;i++) b.a[i]=b.a[i+j];
		for (i=n-j;i<n;i++) b.a[i]=0;
		r.a[0]=mosqrt(b.a[0]);
		for (j=2;j<=n;j<<=1)
		{
			r.a.resize(j);
			q=~r;f.a.resize(j<<1);
			for (i=0;i<j;i++) f.a[i]=b.a[i];
			q.a.resize(j<<1);r.a.resize(j<<1);
			init(j<<1);
			q.dft();r.dft();f.dft();
			for (i=0;i<j<<1;i++) if ((r.a[i]=(ll)q.a[i]*((ll)r.a[i]*r.a[i]%p+f.a[i])%p)&1) r.a[i]=r.a[i]+p>>1; else r.a[i]>>=1;
			r.dft(1);
			for (i=j;i<j<<1;i++) r.a[i]=0;
		}
		r.a.resize(n);
		for (i=n-1;i>=l;i--) r.a[i]=r.a[i-l];
		for (i=0;i<l;i++) r.a[i]=0;
		return r;
	}
#endif
	Q ln(Q b) {return (b.dao()/b).ji();}
#ifdef MTT
	Q exp(Q f)
	{
		Q q(2),r(2);
		ui n=f.a.size()<<1,i,j,k;
		r.a[0]=1;
		for (j=2;j<=n;j<<=1)
		{
			init(j);k=j>>1;
			r.a.resize(j);
			q.a.resize(j);
			for (i=0;i<k;i++) q.a[i]=f.a[i];
			r=r*(q-ln(r)+1);
			r.a.resize(k);
		}
		return r;
	}
#else
	Q exp(Q b)
	{
		Q q(2),r(2);
		ui n=b.a.size(),i,j;
		r.a[0]=1;
		for (j=2;j<=n;j<<=1)
		{
			r.a.resize(j);
			q=ln(r);
			for (i=0;i<j;i++) if ((q.a[i]=b.a[i]+p-q.a[i])>=p) q.a[i]-=p;
			if (++q.a[0]==p) q.a[0]=0;
			r.a.resize(j<<1);q.a.resize(j<<1);
			init(j<<1);
			r.dft();q.dft();
			for (i=0;i<j<<1;i++) r.a[i]=(ll)r.a[i]*q.a[i]%p;
			r.dft(1);
			r.a.resize(j);
		}
		return r;
	}
	void mul(Q &a,Q &b)
	{
		ui n=a.a.size();init(n);
		a.dft();b.dft();
		for (ui i=0;i<n;i++) a.a[i]=(ll)a.a[i]*b.a[i]%p;
		a.dft(1);
	}
	Q exp_new(Q b)
	{
		Q h(2),f(2),r(2),u(2),v(2);
		ui n=b.a.size(),i,j,k;
		r.a[0]=1;h.a[0]=1;
		for (j=2;j<=n;j<<=1)
		{
			f.a.resize(j);
			for (i=0;i<j;i++) f.a[i]=b.a[i];
			f=f.dao();
			k=j>>1;
			for (i=0;i<k-1;i++) {if ((f.a[i+k]+=f.a[i])>=p) f.a[i+k]-=p;f.a[i]=0;}
			for (i=k-1;i<j;i++) if (f.a[i]) f.a[i]=p-f.a[i];
			u.a.resize(k);v.a.resize(k);
			for (i=0;i<k;i++) u.a[i]=r.a[i],v.a[i]=h.a[i];
			u=u.dao();
			mul(u,v);
			for (i=0;i<k-1;i++) if ((f.a[i+k]+=u.a[i])>=p) f.a[i+k]-=p;
			if ((f.a[k-1]+=u.a[k-1])>=p) f.a[k-1]-=p;
			for (i=0;i<k;i++) u.a[i]=r.a[i];
			u.dft();
			for (i=0;i<k;i++) u.a[i]=(ll)u.a[i]*v.a[i]%p;
			u.dft(1);
			if (u.a[0]) --u.a[0]; else u.a[0]=p-1;
			u.a.resize(j);v.a.resize(j);
			init(j);
			for (i=0;i<k;i++) v.a[i]=b.a[i];
			v=v.dao();
			mul(u,v);
			for (i=0;i<k;i++) if (f.a[i+k]<u.a[i]) f.a[i+k]+=p-u.a[i]; else f.a[i+k]-=u.a[i];
			f=f.ji();
			for (i=0;i<k;i++) u.a[i]=r.a[i];
			for (i=k;i<j;i++) u.a[i]=0;
			mul(u,f);
			r.a.resize(j);
			for (i=k;i<j;i++) if (u.a[i]) r.a[i]=p-u.a[i]; else r.a[i]=0;
			if (j!=n) h=~r;
		}
		return r;
	}
	Q sqrt_new(Q b)
	{
		Q q(2),r(2),h(2);
		ui n=b.a.size();
		int i,j=n,k,l;
		for (i=0;i<n;i++) if (b.a[i]) {j=i;break;}
		if (j==n) return b;
		if (j&1) {puts("-1");exit(0);}l=j>>1;
		for (i=0;i<n-j;i++) b.a[i]=b.a[i+j];
		for (i=n-j;i<n;i++) b.a[i]=0;
		r.a[0]=mosqrt(b.a[0]);h.a[0]=ksm(r.a[0],p-2);
		r.a.resize(1);ui i2=ksm(2,p-2);
		for (j=2;j<=n;j<<=1)
		{
			k=j>>1;
			q=r;
			init(k);q.dft();
			for (i=0;i<k;i++) q.a[i]=(ll)q.a[i]*q.a[i]%p;
			q.dft(1);
			q.a.resize(j);
			for (i=k;i<j;i++) q.a[i]=(ll)(q.a[i-k]+p*2u-b.a[i]-b.a[i-k])*i2%p;
			for (i=0;i<k;i++) q.a[i]=0;
			h.a.resize(j);
			mul(q,h);
			r.a.resize(j);
			for (i=k;i<j;i++) if (q.a[i]) r.a[i]=p-q.a[i];
			if (j!=n) h=~r;
		}
		r.a.resize(n);
		for (i=n-1;i>=l;i--) r.a[i]=r.a[i-l];
		for (i=0;i<l;i++) r.a[i]=0;
		return r;
	}
	Q pow(Q b,ui m)
	{
		ui n=b.a.size();
		int i,j=n,k;
		for (i=0;i<n;i++) if (b.a[i]) {j=i;break;}
		if (j==n) return b;
		if ((ll)j*m>=n)
		{
			for (j=0;j<n;j++) b.a[j]=0;
			return b;
		}
		for (i=0;i<n-j;i++) b.a[i]=b.a[i+j];
		for (i=n-j;i<n;i++) b.a[i]=0;
		k=b.a[0];assert(k);
		b=exp_new(ln(b*ksm(k,p-2))*m)*ksm(k,m);
		j*=m;
		for (i=n-1;i>=j;i--) b.a[i]=b.a[i-j];
		for (i=0;i<j;i++) b.a[i]=0;
		return b;
	}
	Q pow2(Q b,ui m)
	{
		Q r(b.a.size());r.a[0]=1;
		while (m)
		{
			if (m&1) r=r*b;
			if (m>>=1) b=b*b;
		}
		return r;
	}
	pair<Q,Q> div(Q a,Q b)
	{
		assert(a.a.size()==b.a.size());
		int n=-1,m=-1;
		for (int i=a.a.size()-1;i>=0;i--) if (a.a[i]) {n=i+1;break;}
		for (int i=b.a.size()-1;i>=0;i--) if (b.a[i]) {m=i+1;break;}
		assert(n+m-1<a.a.size()&&m>=0);
		Q c(n),d(2);
		if (n<m) return make_pair(c,a);
		c=a;d=b;
		reverse(c.a.begin(),c.a.begin()+n);
		reverse(d.a.begin(),d.a.begin()+m);
		c.a.resize(cal(n-m+1));d.a.resize(c.a.size());
		d=~d;
		for (int j=n-m+1;j<c.a.size();j++) c.a[j]=d.a[j]=0;
		c*=d;
		for (int j=n-m+1;j<c.a.size();j++) c.a[j]=0;
		reverse(c.a.begin(),c.a.begin()+n-m+1);
		n=a.a.size();
		a.a.resize(n);c.a.resize(n);b.a.resize(n);
		d=a-c*b;assert(c.a.size()==n);assert(d.a.size()==n);
		for (int i=m;i<d.a.size();i++) assert(d.a[i]==0);
		return make_pair(c,d);
	}
	Q sin(Q &f) {return (exp(f*I)-exp(f*(p-I)))*ksm(2*I%p,p-2);}
	Q cos(Q &f) {return (exp(f*I)+exp(f*(p-I)))*ksm(2,p-2);}
	Q tan(Q &f) {return sin(f)/cos(f);}
	Q asin(Q &f) {return (f.dao()/sqrt((f*f-1)*(p-1))).ji();}
	Q acos(Q &f) {return ((f.dao()/sqrt((f*f-1)*(p-1)))*(p-1)).ji();}
	Q atan(Q &f) {return (f.dao()/(f*f+1)).ji();}
	Q cdq_inv(Q &f)
	{
		return (~(f-1))*(p-1);//g_0=1,g_i=g_{i-j}*f_j
	}
	ui dt(Q f,Q &a,int m,int k)//find a_m,a_n=a_{n-i}*f_i,f_1...k,a_0...k-1
	{
		ui n=cal(k+1<<1),i,ans=0;//cout<<n<<endl;
		f.a.resize(n);
		reverse(f.a.begin(),f.a.begin()+k);
		for (i=0;i<k;i++) if (f.a[i]) f.a[i]=p-f.a[i];
		f.a[k]=1;
		Q g(n),r(n);g.a[1]=1;r.a[0]=1;//cout<<g.a.size()<<endl;
		while (m)
		{
			if (m&1) r=div(r*g,f).second;
			init(n);g.dft();
			for (i=0;i<n;i++) g.a[i]=(ll)g.a[i]*g.a[i]%p;
			g.dft(1);g=div(g,f).second;m>>=1;
		}
		for (i=0;i<k;i++) ans=(ans+(ll)a.a[i]*r.a[i])%p;
		return ans;
	}
#endif
	Q read(int n)
	{
		Q r(n);
		int x;
		for (int i=0;i<n;i++) cin>>x,x%=p,x+=p,r.a[i]=x%p;
		//for (int i=0;i<n;i++) cin>>r.a[i];
		return r;
	}
	void write(Q &r,int n)
	{
		if (n==0) return;
		for (int i=0;i<n-1;i++) cout<<r.a[i]<<" ";
		cout<<r.a[n-1]<<endl;
	}
#ifdef normal
	Q dv(Q *a,int n)
	{
		if (n==1) return a[0];
		int m=n>>1;
		return dv(a,m)*dv(a+m,n-m);
	}
#endif
}
#define poly NTT::Q
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=2.5e5+2;
const ui p=998244353;
vector<int> e[N];
poly f[N];
ui fac[N];
bool ed[N];
void dfs1(int u)
{
	int c=0;
	ed[u]=1;
	for (int v:e[u]) if (!ed[v]) dfs1(v),++c;
	f[u].a[0]=c;f[u].a[1]=1;
	ed[u]=0;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i;
	cin>>n;
	for (i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		e[u].push_back(v);e[v].push_back(u);
	}
	dfs1(1);
	auto g=dv(f+1,n);g.a.resize(NTT::cal(n+1));
	//for (i=0;i<=n;i++) cout<<g.a[i]<<" \n"[i==n];
	fac[0]=1;
	for (i=1;i<=n;i++) fac[i]=(ll)fac[i-1]*i%p;
	ui r=0;
	for (i=0;i<=n;i++) if (1^n-i&1) r=(r+(ll)fac[i]*g.a[i])%p; else r=(r+(ll)(p-fac[i])*g.a[i])%p;
	cout<<r<<endl;
}