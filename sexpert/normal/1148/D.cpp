#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct arrow {
	int src, dst, idx;
	bool operator< (const arrow &o) const { return src < o.src; }
};

const int MAXN = 3e5 + 5;
vector<arrow> forwarda, backwarda;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if(a < b)
			forwarda.push_back({a, b, i + 1});
		else
			backwarda.push_back({a, b, i + 1});
	}
	if(forwarda.size() > backwarda.size()) {
		sort(forwarda.rbegin(), forwarda.rend());
		cout << forwarda.size() << '\n';
		for(auto a : forwarda)
			cout << a.idx << " ";
		cout << '\n';
	}
	else {
		sort(backwarda.begin(), backwarda.end());
		cout << backwarda.size() << '\n';
		for(auto a : backwarda)
			cout << a.idx << " ";
		cout << '\n';
	}
}