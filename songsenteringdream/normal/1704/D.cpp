#include<cstdio>
#include<vector>
using namespace std;
const int o=1e5+10;
int T,n,m;__int128 s[o];vector<long long> a[o];bool flg;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i){
			a[i].resize(m);s[i]=0;
			for(int j=0;j<m;++j) scanf("%lld",&a[i][j]);
			for(int j=1;j<m;++j) a[i][j]+=a[i][j-1];
			for(int j=0;j<m;++j) s[i]+=a[i][j];
		}
		flg=1;
		for(int i=2;i<=n;++i) flg&=(s[1]!=s[i]);
		if(flg) printf("1 %lld\n",(long long)(s[2]-s[1]));
		else for(int i=2;i<=n;++i) if(s[i]^s[1]) printf("%d %lld\n",i,(long long)(s[1]-s[i]));
	}
	return 0;
}