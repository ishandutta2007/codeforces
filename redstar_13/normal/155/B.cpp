#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> pii;
pii a[1010];
bool cmp(pii u,pii v){
	if(u.y==v.y) return u.x<v.x;
	return u.y<v.y;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) cerr<<a[i].x<<' ';
	int cnt=1,ans=0;
	for(int i=n;i>=1;i--){
		if(cnt>0){
			ans+=a[i].x;
			cnt--;
			cnt+=a[i].y;	
		}
		else break;
	}
	cout<<ans<<endl;
			


	return 0;
}