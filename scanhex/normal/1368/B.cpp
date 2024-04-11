#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	nagai k;
	cin >> k;
	int sz=10;
	vector<int>c(sz, 1);
	nagai ans=1;
	int cur=0;
	while(ans < k){ 
		ans/=c[cur];
		++c[cur];
		ans*=c[cur];
		if(++cur == sz)
			cur = 0;
	}
	string s = "codeforces";
	for(int i=0;i<sz;++i)
		for(int j=0;j<c[i];++j)
			cout << s[i];
	cout << '\n';
	return 0;
}