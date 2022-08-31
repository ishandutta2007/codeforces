#include <bits/stdc++.h>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <unordered_map>

using namespace std;

int main(){
	int n,k,m;
	cin >> n >> k >> m;
	unordered_map <string, int> umap;
	vector<string> vec(n);
	vector<int> vec1(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}
	int a;
	for(int i=0;i<n;i++){
		cin >> a;
		umap[vec[i]] = a;
		vec1[i] = a;
	}
	for(int i=0;i<k;i++){
		int mi = INT_MAX;
		cin >> a;
		std::vector<int> v(a);
		for(int i=0;i<a;i++){
			cin >> v[i];
			v[i]--;
			mi = min(mi,vec1[v[i]]);
		}
		for(int i=0;i<a;i++){
			umap[vec[v[i]]] = mi;
		}
	}
	vector<string> inp(m);
	long long int ans=0;
	for(int i=0;i<m;i++){
		cin >> inp[i];
		ans+=umap[inp[i]];
	}
	cout << ans;
}