#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=4e6+10;
int n,m,f[o],a[o];
inline int fix(int x){return x+(x>>31&m);}
inline void modify(int pos,int val){for(;pos<=n;pos+=(pos&-pos)) a[pos]=fix(a[pos]+val-m);}
inline int query(int pos){int res=0;for(;pos;pos-=(pos&-pos)) res=fix(res+a[pos]-m);return res;}
int main(){
	read(n);read(m);modify(1,1);modify(2,m-1);
	for(int i=1;i<=n;++i){
		f[i]=fix(query(i)+f[i-1]-m);
		for(int j=2;i*j<=n;++j) modify(i*j,f[i]),modify((i+1)*j,m-f[i]);
		f[i]=fix(f[i]+f[i-1]-m);
	}
	printf("%d",fix(f[n]-f[n-1]));
	return 0;
}