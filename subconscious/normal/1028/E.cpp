#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define la(x) (x==1?n:x-1)
#define nt(x) (x==n?1:x+1)
using namespace std;
const int N=2e5+5,P=1e9+7;
typedef long double ld;
typedef long long ll;
int n,a[N];ll s[N];
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",a+i);
	int mi=0x3f3f3f3f,ma=-1;
	rep(i,n)mi=min(mi,a[i]),ma=max(ma,a[i]);
	if(mi==ma){
		if(mi==0){
			puts("YES");
			rep(i,n)printf("%d%c",233," \n"[i==n]);
			return 0;
		}
		puts("NO");
		return 0;
	}
	int fir=-1,tmp;
	rep(i,n)if(a[i]==ma&&a[la(i)]<ma){fir=i;break;}
	s[fir]=ma;tmp=la(fir);
	s[tmp]=a[tmp]+2*s[fir];
	for(int i=la(tmp);i!=fir;i=la(i))
		s[i]=a[i]+s[nt(i)];
	puts("YES");
	rep(i,n)printf("%lld%c",s[i]," \n"[i==n]);
	return 0;
}