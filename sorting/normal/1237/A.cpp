#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 7;

int a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	int cnt = 0;
	for(int i = 0; i < n; ++i){
		cin >> a[i];
		if(a[i] & 1){
			if(cnt & 1){
				if(a[i] > 0){
					cout << a[i] / 2 << "\n";
				}
				else{
					cout << a[i] / 2 - 1 << "\n";
				}
			}
			else{
				if(a[i] > 0){
					cout << a[i] / 2 + 1 << "\n";
				}
				else{
					cout << a[i] / 2 << "\n";
				}
			}
			++cnt;
		}
		else{
			cout << a[i] / 2 << "\n";
		}
	}

	return 0;
}