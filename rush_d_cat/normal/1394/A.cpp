#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,d,m;
LL a[N];
vector<LL> v1,v2;
LL pre[N];
int main() {
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<=m) v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	sort(v1.begin(),v1.end()); reverse(v1.begin(),v1.end());
	sort(v2.begin(),v2.end()); reverse(v2.begin(),v2.end());
	LL ans=0;
	pre[0]=0;
	for(int i=1;i<=v2.size();i++){
		pre[i]=pre[i-1]+v2[i-1];
	}
	LL sum1=0;
	for(int i=0;i<=v1.size();i++){
		if(i>0)sum1+=v1[i-1];
		int rem=n-i;
		int cnt=(rem+d)/(d+1);
		LL sum2=pre[min(cnt,(int)v2.size())];
		ans=max(ans,sum1+sum2);
	}
	cout<<ans<<endl;
}