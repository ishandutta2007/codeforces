#include <bits/stdc++.h>

using namespace std;
#define maxn 1000010
int par[maxn];
int val[maxn];
int ch[maxn]; //number of children
int same[maxn];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	ch[1] = 0;
	for (int i = 2; i <= n+1; i++) {
		cin >> par[i];
	}
	ans = 0;
	for (int i = 2; i <= n+1; i++) {
		val[i] = 1;
		same[i] = 0; //number of children with same size as me
		ch[i] = 0;
		ch[par[i]]++;
		int cur = i;
		while (par[cur] != 1) {
			if (val[par[cur]] == val[cur]) { //already have one of these
				//children constraint makes sure ones don't double themselves
				if (same[par[cur]] == 0) {
					same[par[cur]]++;
					break;
				}
				same[par[cur]] = 0; //now it is 0
				val[par[cur]]++;
				// cout << "changed:   " << par[cur] << " " << val[par[cur]] << endl;
				cur = par[cur];
			}
			else if (val[par[cur]] < val[cur]) {
				val[par[cur]] = val[cur];
				same[par[cur]] = 1;
				// cout << "direct change:   " << par[cur] << " " << val[par[cur]] << endl;
				cur = par[cur];
			}
			else break;
		}
		if (par[cur] == 1) ans = max(ans, val[cur]);
		// cout << "ans after inserting   " << i << ":  " ; //debugging
		cout << ans << " ";
		// cout << endl; //debugging
	}
	cout << endl;
	cin >> ans;

}