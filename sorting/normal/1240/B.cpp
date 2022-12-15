#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 7;

int a[MAXN];
int l[MAXN], r[MAXN];
int cnt;

void solve(){
	int n;

	cin >> n;
	cnt = 0;

	for(int i = 1; i <= n; ++i){
		l[i] = n + 1;
		r[i] = -1;
	}

	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		if(l[a[i]] == n + 1){
			++cnt;
		}
		l[a[i]] = min(i, l[a[i]]);
		r[a[i]] = max(i, r[a[i]]);
	}

	int ans = 0;

	int i = 1;
	while(i <= n){
		if(l[i] == n + 1){
			++i;
			continue;
		}

		int j = i, cnt_here = 1, pr = r[j];
		//cout << pr << " pr "<< endl;
		for(j = j + 1; j <= n; ++j){
			if(l[j] == n + 1){
				continue;
			}
			//cout << l[j] << " l[j]" << endl;
			if(l[j] < pr){
				break;
			}
			pr = r[j];
			++cnt_here;
		}
		//cout << i << " - " << cnt_here << endl;
		ans = max(ans, cnt_here);
		i = j;
	}

	cout << cnt - ans << "\n";

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;

	cin >> q;

	while(q--){
		solve();
	}

	return 0;
}