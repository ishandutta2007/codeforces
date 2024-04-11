#include <bits/stdc++.h>
using namespace std;
const int N=100000+10;
typedef long long LL;
int t,n;
char s[N];
int pre[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s+1);
		map<int,int> mp; mp[0]=1;
		LL ans=0;
		for(int i=1;i<=n;i++){
			pre[i]=pre[i-1]+(int)(s[i]-'0')-1;
			ans+=mp[pre[i]]; mp[pre[i]]++;
		}
		printf("%lld\n", ans);
	}
}