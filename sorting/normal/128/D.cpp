#include <bits/stdc++.h>

using namespace std;

inline void answer(bool ans){
	if(ans)
		cout << "YES\n";
	else
		cout << "NO\n";
}

const int MAXN = 1e5 + 7;
int a[MAXN];
map<int, int> cnt;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	if(n & 1){
		answer(false);
		return 0;
	}

	for(int i = 0; i < n; ++i){
		cin >> a[i];
		++cnt[a[i]];
	}

	int mn = cnt.begin()->first;
	++cnt[mn];

	int curr = mn, num = 0;;
	while(true){
		--cnt[curr];
		++num;
		if(cnt[curr - 1] > 1){
			curr = curr - 1;
		}
		else if(cnt[curr + 1] >= 1){
			curr = curr + 1;
		}
		else if(cnt[curr - 1] >= 1){
			curr = curr - 1;
		}
		else{
			break;
		}
	}

	answer(num == n + 1);

	return 0;
}