#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
#define write(a) printf("%d",a)
inline int Min(int a,int b){return a<b?a:b;}
const int o=2e5+10;
int n,m,a[o][3][3];char s[o];
int main(){
	read(n);read(m);scanf("%s",s+1);
	for(int i=1;i<=n;++i) for(int j=0;j<3;++j) for(int k=0;k<3;++k){a[i][j][k]=a[i-1][j][k];if(s[i]!=k+97&&i%3==j) ++a[i][j][k];}
	for(int l,r;m--;putchar('\n')){
		read(l);read(r);
		write(Min(Min(a[r][0][0]-a[l-1][0][0]+a[r][1][1]-a[l-1][1][1]+a[r][2][2]-a[l-1][2][2],
		a[r][0][0]-a[l-1][0][0]+a[r][2][1]-a[l-1][2][1]+a[r][1][2]-a[l-1][1][2]),Min(Min(
		a[r][1][0]-a[l-1][1][0]+a[r][0][1]-a[l-1][0][1]+a[r][2][2]-a[l-1][2][2],
		a[r][1][0]-a[l-1][1][0]+a[r][2][1]-a[l-1][2][1]+a[r][0][2]-a[l-1][0][2]),Min(
		a[r][2][0]-a[l-1][2][0]+a[r][1][1]-a[l-1][1][1]+a[r][0][2]-a[l-1][0][2],
		a[r][2][0]-a[l-1][2][0]+a[r][0][1]-a[l-1][0][1]+a[r][1][2]-a[l-1][1][2]))));
	}
	return 0;
}