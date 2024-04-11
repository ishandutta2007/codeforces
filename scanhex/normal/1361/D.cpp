#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

const int N=500500;
pair<nagai,nagai> rofl[N];

nagai gcd(nagai a, nagai b) {
	if (a < 0) 
		a = -a;
	if (b < 0)
		b = -b;
	if (a == 0 && b == 0)
		return 123123;
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	return __gcd(a,b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(30);
	int n,k;
	cin >> n >> k;
	vector<pair<int,int>> dirs;
	for(int i=0;i<n;++i) {
		nagai x,y;
		cin >> x >> y;
		nagai d=gcd(x,y);
		dirs.emplace_back(x/d,y/d);
		rofl[i]={x,y};
	}
	sort(dirs.begin(),dirs.end());
	dirs.erase(unique(dirs.begin(),dirs.end()),dirs.end());
	vector<vector<double>>dsts(dirs.size());
	for(int i=0;i<n;++i){
		auto&x = rofl[i];
		nagai d=gcd(x.first,x.second);
		pair<int,int> p(x.first/d,x.second/d);
		int ind=lower_bound(dirs.begin(),dirs.end(),p)-dirs.begin();
		dsts[ind].push_back(hypot(x.first,x.second));
	}
	vector<tuple<double,int,int>>arr;
	for(int i=0;i<dirs.size();++i){
		auto&v=dsts[i];
		sort(v.begin(),v.end());
		for(int j=max(0,(int)v.size()-k);j<v.size();++j){
			arr.emplace_back(v[j] * (k - 1 - 2 * ((int)v.size() - j - 1)), i, j);
		}
	}
	sort(arr.rbegin(),arr.rend());
	double ans=0;
	int cnt=0;
	vector<int>cs(dirs.size());
	for(;cnt<k&&cnt<arr.size();++cnt){
		if (get<0>(arr[cnt]) >= 0) 
			ans += get<0>(arr[cnt]), cs[get<1>(arr[cnt])]++;
		else 
			break;
	}
	if (cnt >= k) {
		 cout << ans << '\n';
		 return 0;
	}
	arr.clear();
	for(int i=0;i<dirs.size();++i){
		auto&v=dsts[i];
		if (v.size() == cs[i]) {
			continue;
		}
		for(int j=0; j + cs[i] < v.size(); ++j){
			++cnt;
			int rest = cs[i] + (k - cnt);
			ans += v[j] * (k - 1 - 2 * rest);
			if (cnt == k)
				break;
		}
	}
	cout << ans << '\n';
	return 0;
}