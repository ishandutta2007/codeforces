#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int T,n,a,b,c,One,cnt,L,R,d[o],e[o];char s[o];long long ans;
inline void calc(bool tp){
	long long cur=0;
	for(int i=1;i<=cnt;++i) e[i]=d[i];
	for(int tl=L,tr=R,one=One,p1=1,p2=1;1;tp^=1,ans=max(ans,cur))
		if(tp) if(!one) return;else cur+=b,--one;
		else{
			for(;p1<=cnt&&e[p1]<2;++p1);
			if(!one){
				if(p1<=cnt||tl>1||tr>1) ans=max(ans,cur+a);
				if(p2<p1) ++one,++p2,cur-=c;
				else return;
			}
			else if(p1<=cnt) --e[p1],cur+=a;
			else if(tl>1) --tl,cur+=a;
			else if(tr>1) --tr,cur+=a;
			else if(p2<p1) ++one,++p2,cur-=c;
			else if(tl) tl=0,cur-=c;
			else if(tr) tr=0,cur-=c;
			else return;
		}
}
inline void slv(){
	scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
	for(int i=1,r;i<=n;i=r+1){
		for(r=i;r<n&&s[r+1]==s[i];++r);
		if(s[i]==48) if(i==1) if(r==n){ans=(n>1)*a;return;}
		else L=r-i+1;else if(r==n) R=r-i+1;else d[++cnt]=r-i+1;
		else One+=r-i;
	}
	sort(d+1,d+cnt+1);
	calc(0);calc(1);
}
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=cnt=One=L=R=0) slv();
	return 0;
}