#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	int ptbeg=0;
	int ptend=n-1;
	while(a[ptend-1]==a[ptend])--ptend;
	while(a[ptbeg+1]==a[ptbeg])++ptbeg;
	int ans=0;
	auto check=[&](int i,int j){
		if(a[i]!=a[j])ans=max(ans,abs(i-j));
	};
	for(int i=0;i<n;++i){
		check(i,0);
		check(i,n-1);
		check(i,ptend-1);
		check(i,ptbeg+1);
	}
	cout<<ans<<'\n';
	return 0;
}