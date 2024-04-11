#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[200005];
		int d[200005];
		for(int i = 0; i <= n; i++) d[i] = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			d[a[i]]++;
		}
		int l = 0, r = 0;
		int s = 0;
		int x = 0, y = n + 1;
		for(; l <= n; l++){
			while(r <= n && s < (n + k + 1) / 2) s += d[r++];
			if(s < (n + k + 1) / 2) break;
			if(r - l < y - x){
				x = l;
				y = r;
			}
			s -= d[l];
		}
		cout << x << " " << y - 1 << endl;
		int c = 0;
		int e = 0;
		int last = 0;
		for(int i = 0; i < n; i++){
			if(a[i] >= x && a[i] < y) e++;
			else e--;
			if(e > 0 && c < k - 1){
				cout << last + 1 << " " << i + 1 << endl;
				last = i + 1;
				e = 0;
				c++;
			}
		}
		cout << last + 1 << " " << n << endl;
	}
}