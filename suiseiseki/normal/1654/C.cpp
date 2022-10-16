#include <queue>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n;
int a[Maxn+5];
std::priority_queue<ll> q;
void solve(){
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	while(!q.empty()){
		q.pop();
	}
	std::sort(a+1,a+1+n);
	int pos=n;
	q.push(sum);
	while(pos>0){
		ll val=q.top();
		q.pop();
		if(val==a[pos]){
			pos--;
			continue;
		}
		if(val<a[pos]){
			puts("NO");
			return;
		}
		q.push(val/2);
		q.push((val+1)/2);
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}