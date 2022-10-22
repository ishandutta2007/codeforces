#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

const int N=55;
int n;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	if(count(a,a+n,a[0])*2>n)
		cout<<"Bob\n";
	else
		cout<<"Alice\n";
	return 0;
}