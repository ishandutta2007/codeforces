#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=100100;
const int mod=1e9+7;

nagai arr[N];
nagai solve(nagai n){
	arr[0]=1;
	arr[1]=2;
	arr[2]=4;
	for(int i=3;i<=n;++i)
		arr[i]=(arr[i-2]+arr[i-1])%mod;
	return arr[n];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	cout<<(solve(n)+solve(m)-2+mod)%mod<<'\n';
	return 0;
}