#pragma GCC optimize("O4")
#include<bits/stdc++.h>
using namespace std;
struct Point {
	int x[3];
	inline long long operator*(Point&b) {
		long long ans=0;
		for(int i=0; i<3; i++)ans+=(x[i]*1LL-b.x[i])*(x[i]-b.x[i]);
		return ans;
	}
} P[8];
bool dfs(int x,set<long long>a) {
	if(a.size()>3)return 0;
	if(x==8) {
		return a.size()==3;
	}
	do {
		set<long long>c=a;
		for(int i=x-1; i>=0; i--)c.insert(P[x]*P[i]);
		if(dfs(x+1,c))return 1;
	} while(next_permutation(P[x].x,P[x].x+3));
	return 0;
}
set<long long>s;
int main() {
	for(auto&c:P) {
		for(auto&x:c.x)scanf("%d",&x);
		sort(c.x,c.x+3);
	}
	if(dfs(0,s)) {
		printf("YES\n");
		for(auto&c:P) {
			for(auto&x:c.x)printf("%d ",x);
			printf("\n");
		}
	} else {
		printf("NO\n");
	}
	return 0;
}