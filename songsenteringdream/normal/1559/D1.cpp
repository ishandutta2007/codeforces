#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
#define write(a) printf("%d",a)
const int o=1e5+10;
int n,m1,m2,fa1[o],fa2[o],ans,xx[o],yy[o];
inline int fr1(int x){return x==fa1[x]?x:fa1[x]=fr1(fa1[x]);}
inline int fr2(int x){return x==fa2[x]?x:fa2[x]=fr2(fa2[x]);}
int main(){
	read(n);read(m1);read(m2);
	for(int i=1;i<=n;++i) fa1[i]=fa2[i]=i;
	for(int i,j;m1--;) read(i),read(j),fa1[fr1(i)]=fa1[fr1(j)];
	for(int i,j;m2--;) read(i),read(j),fa2[fr2(i)]=fa2[fr2(j)];
	for(int i=1,t1,t2,t3,t4;i<=n;++i) for(int j=i+1;j<=n;++j)
		if((t1=fr1(i))!=(t2=fr1(j))&&(t3=fr2(i))!=(t4=fr2(j))) fa1[t1]=t2,fa2[t3]=t4,xx[++ans]=i,yy[ans]=j;
	write(ans);putchar('\n');
	for(int i=1;i<=ans;++i,putchar('\n')) write(xx[i]),putchar(' '),write(yy[i]);
	return 0;
}