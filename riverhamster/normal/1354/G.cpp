#include <iostream>
#include <random>
using namespace std;

int ask(int l1, int r1, int l2, int r2){
	cout << "? " << r1 - l1 + 1 << ' ' << r2 - l2 + 1 << ' ' << '\n';
	for(int i=l1; i<=r1; i++)
		cout << i << ' ';
	cout << '\n';
	for(int i=l2; i<=r2; i++)
		cout << i << ' ';
	cout << endl;
	char res[10];
	cin >> res;
	if(res[0] == 'E') return 0;
	if(res[0] == 'F') return 1;
	if(res[0] == 'S') return 2;
	return -1;
}

int main(){
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int T;
	cin >> T;
	mt19937 rnd((unsigned long long)&T);
	while(T--){
		int n, k;
		cin >> n >> k;
		uniform_int_distribution<int> D(2, n);
		bool ok = false;
		for(int i=1; i<=25; i++){
			int pos = D(rnd);
			int r = ask(1, 1, pos, pos);
			if(r == 2){
				cout << "! " << 1 << endl;
				ok = true;
				break;
			}
		}
		if(ok) continue;
		int L, R;
		for(int i=1; i*2<=n; i<<=1){
			int r = ask(1, i, i + 1, 2 * i);
			if(r == 1){
				L = i + 1, R = 2 * i;
				break;
			}
			L = i * 2 + 1, R = n;
		}
		int res = R;
		while(L <= R){
			int mid = (L + R) >> 1;
			if(ask(1, mid - L + 1, L, mid) == 1)
				res = mid, R = mid - 1;
			else L = mid + 1;
		}
		cout << "! " << res << endl;
	}
	return 0;
}