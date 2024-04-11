#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Max(int a,int b){return a>b?a:b;}
const int o=1e6+10;
int n,d,s[o],a[o],mx,cnt,ans,f[o];pair<pair<int,int>,int> p[o];
int main(){
	read(n);read(d);
	for(int i=1;i<=n;++i){
		read(s[i]);read(a[i]);
		if(s[i]>=d) if(s[i]<a[i]) p[++cnt]=make_pair(make_pair(a[i],s[i]),0);
		else p[++cnt]=make_pair(make_pair(s[i],a[i]),1);
	}
	sort(p+1,p+cnt+1);
	for(int i=1,l,r,md;i<=cnt;++i){
		f[i]=f[i-1];mx=Max(mx,p[i].first.second);
		if(p[i].second) ++ans;
		else if(mx<=p[i].first.second){
			for(l=0,r=cnt;l<r;) if(p[md=(l+r>>1)+1].first.first<=p[i].first.second) l=md;else r=md-1;
			f[i]=Max(f[i],f[l]+1);
		}
	}
	printf("%d",f[cnt]+ans);
	return 0;
}