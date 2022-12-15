#include <bits/stdc++.h>

using namespace std;

int xd = 1;
int xe = 5;

const int MAXN = 1e8 + 7;

int mn[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, e, d;

	cin >> n >> d >> e;

	e *= 5;

	for(int i = 0; i <= n; ++i){
		mn[i] = i;
		if(i >= d){
			mn[i] = min(mn[i], mn[i - d]);
		}
		if(i >= e){
			mn[i] = min(mn[i], mn[i - e]);
		}
	}

	cout << mn[n] << endl;

	return 0;
}