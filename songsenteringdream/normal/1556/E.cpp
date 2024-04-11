#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline long long Max(long long a,long long b){return a>b?a:b;}
inline long long Min(long long a,long long b){return a<b?a:b;}
const int o=2e5+10;
int n,q,lg[o];long long a[o],b[o],st[o][20],st2[o][20],s[o];
inline long long query(int l,int r){int t=lg[r-l+1];return Max(st[l][t],st[r-(1<<t)+1][t]);}
inline long long query2(int l,int r){int t=lg[r-l+1];return Min(st2[l][t],st2[r-(1<<t)+1][t]);}
int main(){
	read(n);read(q);
	lg[0]=-1;for(int i=1;i<=n;++i) read(a[i]),lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i) read(b[i]),st2[i][0]=st[i][0]=s[i]=b[i]-a[i]+s[i-1];
	for(int i=1;i<20;++i) for(int j=1;j<=n;++j)
		st[j][i]=(j+(1<<(i-1))<=n)?Max(st[j][i-1],st[j+(1<<(i-1))][i-1]):st[j][i-1],
		st2[j][i]=(j+(1<<(i-1))<=n)?Min(st2[j][i-1],st2[j+(1<<(i-1))][i-1]):st2[j][i-1];
	for(int l,r;q--;){
		read(l);read(r);
		if(s[r]^s[l-1]){printf("-1\n");continue;}
		if(query2(l,r)-s[l-1]<0){printf("-1\n");continue;}
		printf("%lld\n",query(l,r)-s[l-1]);
	}
	return 0;
}