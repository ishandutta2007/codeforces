#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define MN 1000005
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
int n,k,a[MN],sum[MN],ans,cnt[MN];
int b[MN],N;
int tax[MN],id[MN];
bool cmp(int a,int b){
	return 1.0*tax[a]/cnt[a]>1.0*tax[b]/cnt[b];
}
signed main(){
	int n=read();k=read();
	int vv=0;	
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+1+n,[](int a,int b){return a>b;});
	int pos=1;
	for(int i=1;i<=n;++i){
		if(vv<0)break;
		ans+=vv;
		vv+=a[i];
		pos=i+1;
	}
	b[++N]=vv;
//	cerr<<"vv: "<<vv<<endl;
//	cerr<<"ans: "<<ans<<endl;
	for(int i=pos;i<=n;++i){
		b[++N]=a[i];
	//	cerr<<"ins: "<<a[i]<<endl;
	}
	sort(b+1,b+1+N);reverse(b+1,b+1+N);
	for(int i=1;i<=N;++i){
		if(i>=k+1)sum[i]=sum[i-k-1];
		ans+=sum[i];
		sum[i]+=b[i];
	}
	printf("%lld\n",ans);
	return 0;
}