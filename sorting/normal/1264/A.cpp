#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5 + 7;

int p[MAXN];

void solve(){
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> p[i];
	}

	vector<int> v;
	int start = 0;
	for(int i = 0; i < n / 2; ++i){
		if(p[i] != p[i + 1]){
			v.push_back(i - start + 1);
			start = i + 1;
			continue;
		}
	}

	if((int)v.size() < 3){
		cout << "0 0 0\n";
		return;
	}

	int g = v[0], s = 0, b = 0;
	for(int i = 1; i < (int)v.size(); ++i){
		if(s <= g){
			s += v[i];
		}
		else{
			b += v[i];
		}
	}

	if(s <= g || b <= g){
		cout << "0 0 0\n";
		return;
	}

	cout << g << " " << s << " " << b << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		solve();
	}
}