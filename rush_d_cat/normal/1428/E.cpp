#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,k;
LL a[N];
struct Nod {
	LL x, det; int c;
	bool operator<(const Nod&o)const{
		return det < o.det;
	}
};
LL cal(LL x,LL c) {
	LL ave=x/c;
	LL cnt1=x%c;
	LL cnt2=c-x%c;
	return cnt2*ave*ave + cnt1*(ave+1)*(ave+1);
}

int main() {
	scanf("%d%d",&n,&k);
	priority_queue<Nod> q;
	LL ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		//printf("# %lld %lld\n", cal(a[i],2), cal(a[i],1));
		q.push((Nod){a[i], cal(a[i],1) - cal(a[i],2), 1});
		ans += a[i]*a[i];
	}
	for(int i=1;i<=k-n;i++){
		Nod now = q.top(); q.pop(); 
		//printf("%lld %lld %d\n", now.x,now.det,now.c);
		ans -= now.det;
		q.push((Nod){now.x, cal(now.x,now.c+1) - cal(now.x,now.c+2), now.c + 1});
	}
	printf("%lld\n", ans);

}