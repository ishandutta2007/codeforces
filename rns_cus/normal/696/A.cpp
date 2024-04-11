#include<bits/stdc++.h>
using namespace std;

unordered_map <long long, long long> mp;
int z, t, q;
long long x, y;

int main(){
	//freopen("b.in", "r", stdin);
	for(scanf("%d", &q); q --; ){
		scanf("%d %I64d %I64d", &t, &x, &y);
		if(t == 1){
			scanf("%d", &z);
			while(x != y){
				if(x > y){ mp[x] += z; x >>= 1; }
				else{ mp[y] += z; y >>= 1; }
			}
		}
		else{
			long long ans = 0;
			while(x != y){
				if(x > y){ ans += mp[x]; x >>= 1; }
				else{ ans += mp[y]; y >>= 1; }
			}
			printf("%I64d\n", ans);
		}
	}
}