#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int T;
int n;
vi v1, v2;

int main() {
	cin >> T;
	rep(tt, T) {
		v1.clear();
		v2.clear();

		cin >> n;

		for (int i = 0; i < n; i += 2) {
			if (i + 1 < n) {
				printf("? %d %d\n", i + 1, i + 2);
				fflush(stdout);
				char c[2];
				scanf("%s", c);
				if (c[0] == '>') {
					v1.pb(i+1);
					v2.pb(i);
				} else {
					v1.pb(i);
					v2.pb(i+1);
				}
			} else {
				v1.pb(i);
				v2.pb(i);
			}
		}
		int p = v1[0];
		for (int i = 1; i < v1.size(); ++i) {
			printf("? %d %d\n", p + 1, v1[i] + 1);
			fflush(stdout);			
			char c[2];
			scanf("%s", c);
			if (c[0] == '>') {
				p = v1[i];
			}		
		}

		int q = v2[0];
		for (int i = 1; i < v2.size(); ++i) {
			printf("? %d %d\n", q + 1, v2[i] + 1);
			fflush(stdout);			
			char c[2];
			scanf("%s", c);
			if (c[0] == '<') {
				q = v2[i];
			}		
		}
		printf("! %d %d\n", p + 1, q + 1);
		fflush(stdout);
	}
	return 0;
}