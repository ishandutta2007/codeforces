#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
int T,c,d;
int main(){
	for(read(T);T--;){
		read(c);read(d);
		if((c&1)^(d&1)) printf("-1\n");
		else if(!c&&!d) printf("0\n");
		else if(c+d==0) printf("1\n");
		else if(c==d) printf("1\n");
		else printf("2\n");
	}
	return 0;
}