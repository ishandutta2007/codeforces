#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n;LL a[N];
vector<LL> buf;
LL ans=0,C;
unordered_map<LL, LL> mp;
LL solve(LL x){
	if(x<=1)return 0;
	if(mp.count(x)) return mp[x];
	//random_shuffle(a+1,a+1+n);
	//printf("%lld\n", ++C);
	LL res=0;
	//printf("solve %lld\n", x);
	for(int i=1;i<=n;i++){
		if(a[i]>=x)res+=min(a[i]%x,x-(a[i]%x));
		else res+=x-a[i];
		if(res>=ans){
			//printf("end %d\n", i);
			return mp[x]=res;
		}
	}
	//printf("end %d\n", n);
	if(res<ans){
		ans=res;
	}
	//printf("x=%lld,res=%d\n", x,res);
	return mp[x]=res;
}
void add(LL x){
	if(x<=0)return;
	for(LL i=2;i*i<=x;i++){
		if(x%i==0){
			solve(i);
			while(x%i==0)x/=i;
		}
	}
	solve(x);
}
const LL MOD=1e9+7;
LL myrand(){
	return ((1LL*rand()*rand() + 1) % MOD + rand() ^ rand()) % MOD;
}
int main() {
	srand(clock());
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]%2) ans++;
	}
	if(n==1) {
		return !printf("%d\n",a[1]==1?1:0);
	}
	for(int T=1;T<=20;T++){
		int pos=myrand()%n+1;
		for(LL v=max(a[pos]-1,2LL);v<=a[pos]+1;v++){
			add(v);
		}
	}
	cout<<ans<<endl;
}
/*
5
902505699973 902496199883 902488599811 902482899757 902477199703
*/