#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1e5+10;
int T,n,a[o],c1,c2,s1[o],s2[o];long long ans;
inline int Abs(int x){return x<0?-x:x;}
inline void upd(bool x){
	long long res=0;
	for(int i=1;i<=c1;++i) res+=Abs(s1[i]-2*i+x);
	for(int i=1;i<=c2;++i) res+=Abs(s2[i]-2*i+!x);
	if(res<ans) ans=res;
}
int main(){
	for(read(T);T--;c1=c2=0){
		read(n);ans=n*1ll*n;
		for(int i=1;i<=n;++i) read(a[i]),a[i]&=1;
		for(int i=1;i<=n;++i) if(a[i]) s1[++c1]=i;else s2[++c2]=i;
		if(c1+1<c2||c2+1<c1){printf("-1\n");continue;}
		if(c1<=c2) upd(0);
		if(c1>=c2) upd(1);
		printf("%lld\n",ans/2);
	}
	return 0;
}