#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 200005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define vc vector
int T,n,m;
int x[MN],y[MN],z[MN];
const int sgn[2]={1,-1};
void chkmin(int &x,int v){if(x>v)x=v;}
int mx[2][2][2];
int X,Y,Z;
int up(int v,int md){if(abs(v)%2==md)return v;return v+1;}
int dw(int v,int md){if(abs(v)%2==md)return v;return v-1;}
void get(int a,int b,int c){
	assert(abs(a)%2==abs(b)%2&&abs(b)%2==abs(c)%2);
	Z=(b-c)/2;
	X=(a+b)/2;
	Y=(a-c)/2;
}
int calc(){
	int ans=0;
	for(int i=1;i<=n;++i)ans=max(ans,abs(x[i]-X)+abs(y[i]-Y)+abs(z[i]-Z));
	return ans;
}
bool chk(int v){
	for(int j=0;j<2;++j)
		for(int k=0;k<2;++k)
			for(int l=0;l<2;++l)
				mx[j][k][l]=7e18;
	for(int i=1;i<=n;++i){
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				for(int l=0;l<2;++l){
					chkmin(mx[j^1][k^1][l^1],v-(sgn[j]*x[i]+sgn[k]*y[i]+sgn[l]*z[i]));
				}
	}	
	int la=-mx[1][1][0],ra=mx[0][0][1];
	int lb=-mx[1][0][1],rb=mx[0][1][0];
	int lc=-mx[1][0][0],rc=mx[0][1][1];
	int L=-mx[1][1][1],R=mx[0][0][0];
//	cerr<<"v: "<<la<<" "<<ra<<endl;
	if(la>ra||lb>rb||lc>rc||L>R)return 0;
	bool ok=0;
	for(int m=0;m<2;++m){
		if(up(la,m)+up(lb,m)-dw(rc,m)>R||dw(ra,m)+dw(rb,m)-up(lc,m)<L)
			continue;
//		cerr<<"OK"<<endl;
		int A=up(la,m),B=up(lb,m),C=dw(rc,m),ua=dw(ra,m),ub=dw(rb,m),dc=up(lc,m);
		if(A+B-C>=L);
		else if(dw(ua,m)+B-C>=L){
//			cerr<<"AA"<<A<<" "<<dw(ua,m)<<" "<<up(L-(A+B-C),0)<<endl;
			A+=up(L-(A+B-C),0);
		}
		else if(dw(ua,m)+dw(ub,m)-C>=L){
			B+=up(L-(ua+B-C),0);A=dw(ua,m);
//			cerr<<"BB"<<endl;
		}//get(ua,B,C);}
		else {
			C-=up(L-(dw(ua,m)+dw(ub,m)-C),0);
			A=dw(ua,m);B=dw(ub,m);
//			cerr<<"CC"<<endl;
		//	get(ua,ub,C);
		}
		if(A<la||A>ra||B<lb||B>rb||C<lc||C>rc)continue;
		if(A+B-C<L||A+B-C>R)continue;
//		assert(A+B-C>=L&&A+B-C<=R);
		get(A,B,C);
//		cerr<<"OK: "<<A<<" "<<B<<" "<<C<<" XYZ:"<<X<<" "<<Y<<" "<<Z<<" calc:"<<calc()<<endl;
//		cerr<<"FK: "<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<lc<<" "<<rc<<" "<<L<<" "<<R<<endl;
		ok=1;
		break;
	}
	return ok;
}
signed main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	T=read();
	int ca=0;
	while(T--){
		ca++;
		n=read();
		for(int i=1;i<=n;++i){
			x[i]=read(),y[i]=read(),z[i]=read();
	//		if(ca==8)cerr<<"?p "<<x[i]<<" "<<y[i]<<" "<<z[i]<<endl;
		}
		int l=-1,r=3.1e18;
		while(l+1<r){
			int mid=(l+r)>>1;
	//		cerr<<"? "<<l<<" "<<r<<" "<<mid<<endl;
			if(chk(mid))r=mid;
			else l=mid;
		}
	//	cerr<<"r: "<<l<<" "<<r<<" calc: "<<calc()<<endl;
	//	chk(r);
	//	cerr<<"? "<<r<<" "<<calc()<<endl;
	//	assert(calc()==r);
	//	cout<<r<<endl;
		printf("%lld %lld %lld\n",X,Y,Z);
	}
	return 0;
}