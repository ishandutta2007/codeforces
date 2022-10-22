#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%lld",a)
inline long long Min(long long a,long long b){return a<b?a:b;}
int T;long long n,f[30];
int main(){
	for(int i=1;i<21;++i){
		f[i]=1000;
		for(int j=i-1;j>=i-3&&j+1;--j) f[i]=Min(f[i],f[j]+3);
		for(int j=i-1;j>=i-4&&j+1;--j) f[i]=Min(f[i],f[j]+4);
		for(int j=i-1;j>=i-5&&j+1;--j) f[i]=Min(f[i],f[j]+5);
	}
	for(read(T);T--;putchar('\n')){
		read(n);n=(n+1)/2;
		if(n<=20) n=f[n];
		write(n*5);
	}
	return 0;
}