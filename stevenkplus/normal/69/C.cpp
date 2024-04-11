#include <iostream>
#include <sstream>
#include <map>

using namespace std;

#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
const int MAXK = 110;
const int MAXN = 110;

int has[MAXK][MAXN];
int reqs[MAXN][MAXN];

map<string, int> mymap;

int K, N, M, Q;

int main() {
	cin >> K >> N >> M >> Q;
	int cnt = 0;
	for(int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		mymap[tmp] = cnt;
		++cnt;
	}
	string tmp;
	getline(cin, tmp);

	for(int i = 0; i < M; ++i) {
		getline(cin, tmp);
		for(int j = 0; j < int(tmp.size()); ++j) {
			if (tmp[j] == ':' || tmp[j] == ',') {
				tmp[j] = ' ';
			}
		}
		stringstream ss(tmp);

		ss >> tmp;
		mymap[tmp] = cnt;

		string a;
		int b;
		while (ss >> a >> b) {
			reqs[cnt][mymap[a]] += b;
		}
		++cnt;
	}

	for(int i = 0; i < Q; ++i) {
		int x, y;
		cin >> y >> tmp;
		x = mymap[tmp];
		--y;
		++has[y][x];
		for(int j = N; j < N + M; ++j) {
			bool canmake = true;
			for(int k = 0; k < j; ++k) {
				if (has[y][k] < reqs[j][k]) {
					canmake = false;
					break;
				}
			}
			if (canmake) {
				for(int k = 0; k < j; ++k) {
					has[y][k] -= reqs[j][k];
				}
				++has[y][j];
			}
		}
	}

	for(int i = 0; i < K; ++i) {
		int sum = 0;
		for(int j = 0; j < N + M; ++j) {
			if (has[i][j]) ++sum;
		}
		cout << sum << "\n";
		repi(j, mymap) {
			int id = j->second;
			if (has[i][id]) {
				cout << j->first << " " << has[i][id] << "\n";
			}
		}
	}

	return 0;
}