#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> pre = {0};

void solve(int testID){
	int n; cin >> n;
	cout << lower_bound(pre.begin(),pre.end(),n)-pre.begin() << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(int i = 0; i < 50005; ++i){
		pre.push_back(pre.back()+2*(i-i/3));
	}
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);

	}

}