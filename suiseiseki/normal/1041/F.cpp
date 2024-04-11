#include <cstdio>
#include <map>
using namespace std;
#define Maxn 100000
#define Maxm 100000
int a[Maxn+5],b[Maxm+5];
map<int,int> mp;
int mx(int a,int b){
	return a>b?a:b;
}
int mn(int a,int b){
	return a<b?a:b;
}
int n,m;
int ans;
map<int,int>::iterator it;
int check(int x){
	mp.clear();
	for(int i=1;i<=n;i++){
		mp[a[i]%(x<<1)]++;
	}
	for(int i=1;i<=m;i++){
		mp[(b[i]+x)%(x<<1)]++;
	}
	it=mp.begin();
	while(it!=mp.end()){
		ans=mx(ans,(it->second));
		it++;
	}
	return ans;
}
int main(){
	int now;
	scanf("%d%d",&n,&now);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	scanf("%d%d",&m,&now);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		mp[b[i]]++;
	}
	it=mp.begin();
	while(it!=mp.end()){
		ans=mx(ans,(it->second));
		it++;
	}
	for(int i=0;i<30;i++){
		ans=mn(ans,check(1<<i));
	}
	printf("%d\n",ans);
	return 0;
}