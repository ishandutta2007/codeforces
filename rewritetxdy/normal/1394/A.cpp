#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5+10;

int n,d,m,c[N];
ll ans;
priority_queue<int,vector<int>,greater<int> >q;

int main()
{
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i <= n;i++) scanf("%d",&c[i]);
	sort(c+1,c+1+n);
	int x=1;
	for(;x <= n;x++)
		if(c[x] <= m) ans += c[x];
		else break;
	if(x <= n) ans += c[n];
	for(int i=x;i < n;i++) q.push(0);
	for(int i=1;i < x;i++) q.push(c[i]);
	d++;
	for(int i=n-1;i >= x;i--){
		ll sum = 0;
		for(int j=1;j <= d;j++){
			if(q.empty()){
				printf("%lld\n",ans);
				return 0;
			}
			sum += q.top() , q.pop();
		}
		if(sum < c[i])
			ans += c[i]-sum;
		else break;
	}
	printf("%lld\n",ans);
	return 0;
}