#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define sz(x) int((x).size())
typedef vector<int> vi;

const int MAXN = 4100;

vi guys[MAXN];
int ar[MAXN];
int N;
map<int, int> mymap;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d", ar + i);
	}
	int j = 1;
	for(int i = 0; i < N; ++i) {
		int &x = mymap[ar[i]];
		if (!x) x = j++;
		guys[x].push_back(i);
	}

	int longest = 0;
	for(int i = 0; i < j; ++i) {
		longest = max(longest, sz(guys[i]));
		for(int k = i + 1; k < j; ++k) {
			int need = -1;
			int len = 0;
			int a = 0;
			int b = 0;
			vi &x = guys[i];
			vi &y = guys[k];
			while(a < sz(x) || b < sz(y)) {
				if (b == sz(y) || a < sz(x) && x[a] < y[b]) {
					a++;
					if (need == 2) continue;
					len++;
					need = 2;
				} else {
					b++;
					if (need == 1) continue;
					len++;
					need = 1;
				}
			}
			longest = max(longest, len);
		}
	}
	printf("%d\n", longest);
}