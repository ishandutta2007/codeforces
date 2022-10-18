#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	map<string, pii> counts;
	vector<string> words(N);
	rep(ind,0,N) {
		string word;
		cin >> word;
		words[ind] = word;
		rep(i,0,sz(word)) rep(j,i+1,sz(word)+1) {
			string sub = word.substr(i, j - i);
			auto& pa = counts[sub];
			if (pa.first != ind + 1) {
				pa.first = ind + 1;
				pa.second++;
			}
		}
	}

	int Q;
	cin >> Q;
	rep(qi,0,Q) {
		string word;
		cin >> word;
		auto& pa = counts[word];
		if (pa.first == 0) {
			cout << "0 -" << endl;
		} else {
			cout << pa.second << " " << words[pa.first - 1] << endl;
		}
	}
}