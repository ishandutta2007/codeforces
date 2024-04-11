#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
#define write(a) printf("%d",a)
const int o=1010;
int T,n,ans,tmp;char s[o],t[o];
void slv(){
	for(int i=2;i<=n;++i) if(s[i]=='?') if(s[i-1]=='R') s[i]='B';else s[i]='R';
	tmp=0;for(int i=2;i<=n;++i) tmp+=(s[i-1]==s[i]);
}
int main(){
	for(read(T);T--;putchar('\n')){
		read(n);scanf("%s",s+1);
		if(s[1]=='?'){
			for(int i=1;i<=n;++i) t[i]=s[i];
			s[1]='R';slv();ans=tmp;
			for(int i=1;i<=n;++i) s[i]=t[i];
			s[1]='B';slv();
			if(ans>tmp) for(int i=1;i<=n;++i) putchar(s[i]);
			else{
				for(int i=1;i<=n;++i) s[i]=t[i];s[1]='R';
				slv();for(int i=1;i<=n;++i) putchar(s[i]);
			}
		}
		else{slv();for(int i=1;i<=n;++i) putchar(s[i]);}
	}
	return 0;
}