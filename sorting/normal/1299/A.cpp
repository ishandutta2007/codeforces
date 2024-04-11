#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 7;
const int kMaxBits = 30;
int a[kMaxN];
int cnt[kMaxBits];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int i = kMaxBits - 1; i >= 0; --i){
		int curr = -1;
		bool ok = true;
		for(int j = 0; j < n; ++j){
			if(a[j] & (1 << i)){
				if(curr == -1)
					curr = j;
				else{
					ok = false;
					break;
				}
			}
		}

		if(curr != -1 && ok){
			swap(a[curr], a[0]);
			break; 
		}
	}

	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << "\n";
}