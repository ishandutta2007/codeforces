#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 400000 + 10;
int a[N]; LL sum=0;
vector<LL> f;
pair<LL,LL> read(int n){
	LL s1=0,s2=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); sum+=a[i];
	}
	sort(a+1,a+1+n);
	s1=a[1];
	for(int i=2;i<=n;i++) s2+=a[i];
	f.push_back(s1); f.push_back(s2);
	return make_pair(s1,s2);
}
int main() {
	int n1,n2,n3;
	scanf("%d%d%d",&n1,&n2,&n3);
	pair<LL,LL> p1,p2,p3;
	p1=read(n1); p2=read(n2); p3=read(n3);

	LL ans=-1e18;
	
	ans=max(ans, sum - 2*(p1.first + p2.first));
	ans=max(ans, sum - 2*(p1.first + p3.first));
	ans=max(ans, sum - 2*(p2.first + p3.first));
	ans=max(ans, sum - 2*(p1.first + p1.second));
	ans=max(ans, sum - 2*(p2.first + p2.second));
	ans=max(ans, sum - 2*(p3.first + p3.second));

	cout<<ans<<endl;
}