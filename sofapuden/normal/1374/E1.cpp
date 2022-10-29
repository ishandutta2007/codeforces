#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<int> al, bo, to;
	for(int i = 0; i < n; ++i){
		int a, b, c; cin >> a >> b >> c;
		if(b && c)to.push_back(a);
		else if(b)bo.push_back(a);
		else if(c)al.push_back(a);
	}
	sort(al.begin(),al.end());
	sort(bo.begin(),bo.end());
	sort(to.begin(),to.end());
	int cn1 = 0, cn2 = 0;
	int ans = 0;
	for(int i = 0; i < k; ++i){
		if((cn1 == al.size() || cn1 == bo.size()) && cn2 == to.size()){
			cout << -1 << '\n';
			return 0;
		}
		if(cn2 == to.size()){
			ans+=al[cn1]+bo[cn1++];
			continue;
		}
		if(cn1 == al.size() || cn1 == bo.size()){
			ans+=to[cn2++];
			continue;
		}
		if(al[cn1] + bo[cn1] < to[cn2]){
			ans+=al[cn1]+bo[cn1++];
		}
		else{
			ans+=to[cn2++];
		}
	}
	cout << ans << '\n';
}