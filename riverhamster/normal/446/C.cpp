#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<cstdlib>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) ((x)&(-x))
#define sp(x,y) x^=y^=x^=y
using namespace std;
typedef long long ll;
bool o;
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
const int w=1150,mod=1e9+9;
int n,m,a[300001],s[300001],opt,x,y,cnt,ans;
int l[1151],r[1151],d[300005];
int f[300005],sum[300001];
inline int add(int x,int y){
	return x+y<mod?x+y:x+y-mod;
}
inline int sub(int x,int y){
	return x<y?x+mod-y:x-y;
}
inline int query(int l,int r,int x){
	return x>=r?sum[r-l+1]:sum[x-l+1];
}
void rebuild(){
	for(register int i=1;i<=cnt;++i){
		++d[l[i]];
		d[r[i]+1]=sub(d[r[i]+1],f[r[i]-l[i]+2]),d[r[i]+2]=sub(d[r[i]+2],f[r[i]-l[i]+1]);
	}
	cnt=0;
	for(register int i=1;i<=n;++i) s[i]=add(s[i-1],a[i]=add(a[i],d[i]=add(d[i],add(d[i-1],d[i-2]))));
	memset(d,0,sizeof(d));
}
int main(){
  // zjf txdy
	rd(n),rd(m);
	sum[1]=f[1]=f[2]=1,sum[2]=2;
	for(register int i=3;i<=n;++i) f[i]=add(f[i-1],f[i-2]),sum[i]=add(sum[i-1],f[i]);
	for(register int i=1;i<=n;++i) rd(a[i]),s[i]=add(a[i],s[i-1]);
	for(register int i=m/w,j,opt,x,y,k;i;--i){
		for(j=w;j;--j){
		    rd(opt);
		    if(opt&1){
		    	cnt++,rd(l[cnt]),rd(r[cnt]);
		    	continue;
	    	}
	    	rd(x),rd(y);
	    	ans=sub(s[y],s[--x]);
	    	for(k=1;k<=cnt;++k){
	    		if(l[k]>y||r[k]<=x) continue;
		    	ans=add(ans,query(l[k],r[k],y));
		    	if(l[k]<=x) ans=sub(ans,query(l[k],r[k],x));
	    	}
	    	wr(ans),_e;
	    }
	    rebuild();
	}
	for(register int i=m%w,j,opt,x,y;i;--i){
	    rd(opt);
		if(opt&1){
		    cnt++,rd(l[cnt]),rd(r[cnt]);
		    continue;
	    }
	    rd(x),rd(y);
	    ans=sub(s[y],s[--x]);
	    for(j=1;j<=cnt;++j){
	    	if(l[j]>y||r[j]<=x) continue;
		    ans=add(ans,query(l[j],r[j],y));
		    if(l[j]<=x) ans=sub(ans,query(l[j],r[j],x));
	    }
	    wr(ans),_e;
	}
}
template <typename _Tp>
	inline void rd(_Tp &x){
		o=0;
		x=0;
		while (chh^45&&(chh<48||chh>57)) chh=gc();
		if(chh==45)o=1,chh=gc();
		while(chh>47&&chh<58){
			x=(x<<1)+(x<<3)+(chh^48);
			chh=gc();
		}
		if(o) x=-x;
	}
template <typename _Tp>
	inline void wr(_Tp x){
		if(x<0) x=-x,putchar(45);
		if(x<10){
			putchar(x+48);
			return;
		}
		wr(x/10);
		putchar(x%10+48);
	}
template <typename _Tp>
	inline _Tp mx(_Tp x,_Tp y){
		return x>y?x:y;
	}
template <typename _Tp>
	inline _Tp mn(_Tp x,_Tp y){
		return x<y?x:y;
	}