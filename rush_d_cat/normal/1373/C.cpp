#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000002;
int t,sum[N];
map<int,int> mp;
char s[N];
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%s", s+1);
		mp.clear();
		int n=strlen(s+1);
		for(int i=1;s[i];i++){
			sum[i]=sum[i-1]+(s[i]=='+'?1:-1);
			if(mp.count(sum[i]) == 0) mp[sum[i]]=i;
		}
		LL ans=0;
		for(int i=0;;i++){
			int need=-i-1;
			if(mp.count(need))ans+=mp[need];
			else {ans += n; break;}
		}
		printf("%lld\n", ans);
	}
}