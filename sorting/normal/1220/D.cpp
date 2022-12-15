#include <bits/stdc++.h>

using namespace std;

map<long long, vector<long long>> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	vector<long long> ans;
	for(long long i = 0; i < n; ++i){
		long long x;

		cin >> x;

		long long t = 1ll, pr = x;
		while(pr % 2ll == 0ll){
			t *= 2ll;
			pr /= 2ll;
		}
		mp[t].push_back(x);
	}

	long long mx = 0, r;
	for(auto it: mp){
		if(it.second.size() > mx){
			mx = it.second.size();
			r = it.first;
		} 
	}

	for(auto it: mp){
		if(it.first != r){
			for(long long x: it.second){
				ans.push_back(x);
			}
		}
	}

	cout << (long long)(ans.size()) << "\n";
	for(long long x: ans){
		cout << x << " ";
	}
	cout << "\n";

	return 0;
}