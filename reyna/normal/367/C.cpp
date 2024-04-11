//In the name of God
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int Maxn = 1e5 + 1e3;
pair<int,int> arr[Maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m;i++)
		scanf("%d%d",&arr[i].second,&arr[i].first);
	sort(arr,arr+m);
	long long ans = 0;
	for(int i = m-1; i >= 0;i--){
		int ver = m-i;
		long long edge = ((long long)ver * (ver - 1))/2;
		int now = ver - 1;
		if(now % 2)
			now++;
		if((long long)ver * (now/2) <= n && edge <= n-1)
			ans += arr[i].first;
	}
	cout << ans << endl;
	return 0;
}