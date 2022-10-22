#include<cstdio>
#include<cmath>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
inline int Min(int a,int b){return a<b?a:b;}
int T,xx1,yy1,xx2,yy2,W,H,w,h,dx,dy;
int main(){
	for(read(T);T--;){
		read(W);read(H);read(xx1);read(yy1);read(xx2);read(yy2);read(w);read(h);
		dx=2e8;dy=2e8;
		if(xx2-xx1+w<=W) dx=Min(w-xx1,xx2-(W-w));if(dx<0) dx=0;
		if(yy2-yy1+h<=H) dy=Min(h-yy1,yy2-(H-h));if(dy<0) dy=0;
		if(dx==2e8&&dy==2e8){printf("-1\n");}
		else printf("%.6lf\n",(double)Min(dx,dy)); 
	}
	return 0;
}