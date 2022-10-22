#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
#define MN 1000005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int T,n,m;
int a[MN];
int cnt[MN];
vector<int>d[MN];
signed main(){
	T=read();
	for(int i=2;i<=1000000;++i)
		for(int j=i;j<=1000000;j+=i){
			if(j%(i*i)==0)d[j].push_back(i);
		}
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
			int tmp=a[i];
			for(auto j:d[tmp]){
				while(a[i]%(j*j)==0){
					a[i]/=(j*j);
				}
			}
		}
		sort(a+1,a+1+n);
		a[n+1]=0;
		int ans=0,tmp=0,qwq=0;
		for(int i=1;i<=n;++i){
			cnt[a[i]]++;
			if(a[i]!=a[i+1]){
				if(cnt[a[i]]&1){
					ans=max(ans,cnt[a[i]]);
					if(a[i]==1)qwq+=cnt[a[i]];
				}
				else qwq+=cnt[a[i]];
				tmp=max(tmp,cnt[a[i]]);
			}
		}
		for(int i=1;i<=n;++i)cnt[a[i]]=0;
		int q=read();
		while(q--){
			int w=read();
			if(!w)printf("%lld\n",tmp);
			else printf("%lld\n",max(ans,qwq));
		}
	}
	return 0;
}