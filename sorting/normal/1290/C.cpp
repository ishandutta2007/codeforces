#include <bits/stdc++.h>

using namespace std;

const int kInf = 1e9 + 7;

class dsu{
private:
	vector<int> comp, sz;
	vector<int> tp;
	vector<int> onc, offc;
public:
	dsu(int n) : comp(n), sz(n, 1), tp(n, 0), onc(n, 0), offc(n, 1){
		for(int i = 0; i < n; ++i)
			comp[i] = i;
		offc[n - 1] = kInf;
	}
	pair<int, int> getc(int i){
		if(comp[i] != i){
			auto sub = getc(comp[i]);
			comp[i] = sub.first;
			tp[i] ^= sub.second;
		}
		return {comp[i], tp[i]};
	}
	int join(int a, int b, int t){
		int at, bt;
		tie(a, at) = getc(a);
		tie(b, bt) = getc(b);
		t ^= at ^ bt;

		if(a == b)
			return 0;
		if(sz[a] < sz[b]){
			swap(a, b);
			swap(at, bt);
		}

		int add = -(min(onc[a], offc[a]) + min(onc[b], offc[b]));

		sz[a] += sz[b];
		comp[b] = comp[a];
		tp[b] = t;

		if(tp[b]){
			onc[a] += offc[b];
			offc[a] += onc[b];
		}
		else{
			onc[a] += onc[b];
			offc[a] += offc[b];
		}

		add += min(onc[a], offc[a]);
		return add;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> lamps(n, {k, k});

	string str;
	cin >> str;
	for(int j = 0; j < k; ++j){
		int c;
		cin >> c;
		for(int i = 0; i < c; ++i){
			int x;
			cin >> x;
			--x;

			if(lamps[x].first == k)
				lamps[x].first = j;
			else
				lamps[x].second = j;
		}
	}

	dsu d(k + 1);

	int res = 0;
	for(int i = 0; i < n; ++i){
		res += d.join(lamps[i].first, lamps[i].second, str[i] == '0');
		cout << res << "\n";
	}
}