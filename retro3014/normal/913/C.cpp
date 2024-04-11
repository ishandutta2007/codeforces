#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX_N 30
#define INF 1000000000000000000LL
typedef long long ll;
int N, L;
ll arr[MAX_N+1];
ll ans = 0;
ll ans2 = INF;

int main(){
	scanf("%d%d", &N, &L);
	for(int i=0; i<MAX_N; i++){
		if(i<N)	scanf("%lld", &arr[i]);
		else arr[i] = INF;
		if(i==0)	continue;
		arr[i] = min(arr[i], 2*arr[i-1]);
	}
	for(int i=MAX_N-1; i>=0; i--){
		if(L>=(1<<i)){
			L-=(1<<i);
			ans+=arr[i];
		}
		ans2 = min(ans2, ans+arr[i]);
	}
	ans2 = min(ans2, ans);
	printf("%lld", ans2);
}