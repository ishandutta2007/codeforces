#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())


const int N=200200;
nagai arr[N];
nagai kek[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i)
		cin>>arr[i];
	sort(arr,arr+n);
	nagai ans=1;
	for(int i=0;i<n;++i){
		nagai rofl=arr[i]%m;
		for(int j=0;j<m;++j){
			nagai md=rofl-j;
			if (md>=m)md-=m;
			if (md<0)md+=m;
			if (kek[j])
				ans*=md,ans%=m;
		}
		if(++kek[rofl]>1){
			 cout<<0<<'\n';
			 return 0;
		}
	}
	ans%=m;
	cout<<ans<<'\n';
	return 0;
}