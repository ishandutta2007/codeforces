#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 2e5L + 11;
char s[N];

int p[N];
bool vis[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);

	set <int> zeros, ones;
	
	for(int i = 0; i < n; i ++)
		if(s[i] == '1') {
			if(zeros.size() == 0) {
				cout << "-1\n";
				return 0;
			}
			p[i] = *zeros.begin();
			zeros.erase(zeros.begin());
			ones.insert(i);
		} else {
			if(ones.size() == 0) {
				p[i] = -1;
			} else {
				p[i] = *ones.begin();
				ones.erase(ones.begin());
			}
			zeros.insert(i);
		}
	
	if(ones.size()) {
		cout << "-1\n";
		return 0;
	}
	
	vector <vector <int>> v;
	for(int i = n - 1; i >= 0; i --)
		if(!vis[i]) {
			vector <int> u;
			for(int j = i; j != -1; j = p[j]) {
				u.pb(j);
				vis[j] = 1;
			}
			reverse(u.begin(), u.end());
			v.pb(u);
		}
	
	cout << v.size() << '\n';
	for(auto u : v) {
		printf("%d", (int)u.size());
		for(int i : u) printf(" %d", i + 1);
		puts("");
	}
}