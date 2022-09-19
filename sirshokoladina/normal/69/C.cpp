#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

string sn[60], sm[60];
int num[60][60];
map<string, int> mp;
int kn[110][60], km[110][60];
vector<pair<string, int> > ans;

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	forn (i, 60) {
		forn (j, 60) {
			num[i][j] = 0;
		}
	}
	forn (i, 110) {
		forn (j, 60) {
			kn[i][j] = km[i][j] = 0;
		}
	}
	int k, n, m, q;
	cin >> k >> n >> m >> q;
	forn (i, n) {
		cin >> sn[i];
		mp[sn[i]] = i;
	}
	forn (i, m) {
		cin >> sm[i];
		sm[i].resize(sm[i].size() - 1);
		bool b = 1;
		while (b) {
			string s;
			int N;
			char c;
			cin >> s >> N;
			scanf("%c", &c);
			b = (c == ',');
			num[i][mp[s]] = N;
		}
	}
	forn (i, q) {
		int N;
		string s;
		cin >> N >> s;
		N--;
		kn[N][mp[s]]++;
		forn (j, m) {
			bool can = 1;
			forn (l, n) {
				can &= kn[N][l] >= num[j][l];
			}
			if (can) {
				forn (l, n) {
					kn[N][l] -= num[j][l];
				}
				km[N][j]++;
			}
		}
	}
	forn (i, k) {
		ans.clear();
		forn (j, n) {
			if (kn[i][j]) {
				ans.push_back(make_pair(sn[j], kn[i][j]));
			}
		}
		forn (j, m) {
			if (km[i][j]) {
				ans.push_back(make_pair(sm[j], km[i][j]));
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		forn (j, ans.size()) {
			cout << ans[j].first << ' ' << ans[j].second << endl;
		}
	}
}