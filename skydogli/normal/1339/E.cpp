#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 200005
int T,n;
bool vis[MN];
int trans(int x){
	int ti=0,ans=0;
	int tmp=1;
	while(x){
		ans+=(x%4)*tmp;
		ti++;
		tmp*=10;
		x>>=2;
	}
	return ans;
}
const int t[4][4]={{0,0,0,0},{0,1,2,3},{0,2,3,1},{0,3,1,2}};
int trans(int x,int id){
	return t[x][id];
}
int flag;
	vector<int>tmp;
void work(int x,int id){
	int tmp=1,ans=0;
	while(x){
		ans+=trans(x%4,id)*tmp;
//		cerr<<"? "<<x%4<<" "<<id<<endl;
		x>>=2;tmp*=4;
	}
//	assert(::tmp[flag]==ans);
	printf("%lld\n",ans);
}
signed main(){
//	scanf("%lld",&n);
/*	int n=1000;
	tmp.push_back(0);
	for(int i=1;i<=n;++i)
		if(!vis[i])for(int j=1;j<=n;++j)
			if(!vis[j]&&!vis[i])for(int k=1;k<=n;++k){
				if(!vis[k]&&((i^j^k)==0)){
					cout<<trans(i)<<" "<<trans(j)<<" "<<trans(k)<<endl;
				//	cerr<<i<<" "<<j-i<<" "<<k-j<<endl;
					vis[i]=vis[j]=vis[k]=1;
					tmp.push_back(i);
					tmp.push_back(j);
					tmp.push_back(k);
					break;
				}
			}*/
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		flag=n;
		int id=(n-1)%3+1;
		n=(n+2)/3;
		int now=1;
		while(n>now){
			n-=now;
			now<<=2;
		}
		work(now+n-1,id);
	}
	return 0;
}