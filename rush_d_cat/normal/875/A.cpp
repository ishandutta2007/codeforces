#include <bits/stdc++.h>
using namespace std;
int n;
bool chk(int x) {
	int t=x;
	while(t){
		x+=t%10; t/=10;
	}
	return x==n;
}
int main() {
	cin>>n;
	vector<int> ans;
	for(int i=max(n-1000,0);i<=n;i++)
		if(chk(i))
			ans.push_back(i);
	printf("%d\n", ans.size());
	for(auto x: ans) printf("%d ", x);
}