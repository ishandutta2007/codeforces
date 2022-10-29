#include<bits/stdc++.h>

using namespace std;

const int mxN = 1e9;

vector<int> P, C;
vector<int> ord;

int main(){
	int n; cin >> n;
	ord.resize(n);
	vector<int> ans(n);
	std::priority_queue<pair<int,int>> pq;
	for(int i = 0; i < n; ++i){
		int p, c; cin >> p >> c;
		P.push_back(p-1);
		C.push_back(c);
	}
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		int x = i;
		while(P[x] != -1){
			cnt++;
			x = P[x];
		}
		ord[i] = cnt;
	}
	for(int i = 0; i < n; ++i){
		if(C[i] == 0){
			pq.push({-ord[i],i});
		}
	}
	int am = 0;
	int cu = 1;
	while(pq.size()){
		am++;
		auto x = pq.top(); pq.pop();
		ans[x.second] = cu++;
		int z = x.second;
		while(z != -1){
			C[z]--;
			if(C[z] == 0){
				pq.push({-ord[z],z});
			}
			z = P[z];
		}
	}
	if(am != n){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
		for(int i : ans)cout << i << ' ';
		cout << '\n';
	}

}