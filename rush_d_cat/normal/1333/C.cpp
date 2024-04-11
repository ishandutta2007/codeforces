#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;
int n; LL a[N],s[N];
map<LL,int> pre;
int main() {
	scanf("%d", &n);
	pre[0]=0;
	LL ans=0; int lef=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); s[i]=s[i-1]+a[i];
		if(pre.count(s[i])) lef=max(lef,pre[s[i]]+2); 
		pre[s[i]]=i;
		ans+=i-lef+1; 
	}
	cout<<ans<<endl;
}