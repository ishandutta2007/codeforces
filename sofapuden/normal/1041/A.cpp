#include <bits/stdc++.h>
#define all(x) (x.begin(),x.end())

using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v;
	for(int i = 0, tmp; i < n; ++i){
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	cout << v[n-1] - v[0] - n + 1 << "\n";		
}