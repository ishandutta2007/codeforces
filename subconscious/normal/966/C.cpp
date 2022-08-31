#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define y1 FFF
using namespace std;
const int N=100005;
typedef long long ll;
vector<ll>a[65];int n;
int check(ll x){
	ll cc=1;int s=0;
	while(cc*2<=x)cc<<=1,++s;
	return s;
}
ll x,cur,ans[N];
int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%lld",&x),a[check(x)].push_back(x);
	cur=0;
	rep(c,n){
		bool flag=0;
		for(int i=0;i<=64;++i)
			if(!a[i].empty()&&(cur^a[i][a[i].size()-1])>cur){
				ans[c]=a[i][a[i].size()-1];
				cur^=a[i][a[i].size()-1];
				a[i].pop_back(),flag=1;break;
			}
		if(!flag){puts("No");//system("pause");
		return 0;}
	}
	puts("Yes");
	rep(i,n)printf("%lld%c",ans[i],i==n?'\n':' ');
	//cur=0;
	//rep(i,n)printf("%lld%c",(cur^=ans[i]),i==n?'\n':' ');
	//system("pause");
	return 0;
}