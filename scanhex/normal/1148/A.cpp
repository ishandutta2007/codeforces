#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	nagai a,b,c;
	cin>>a>>b>>c;
	a=min(a,b+1);
	b=min(b,a+1);
	cout<<2*c+a+b<<'\n';
	return 0;
}