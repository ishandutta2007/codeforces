#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 1e5 + 11;
int a[N];

int main() {
	ios :: sync_with_stdio(0);
	
	int t; cin >> t;
	while(t --) {
		int n; cin >> n;
		vector <int> v;
		
		int last = 0;
		for(int i = 0; i < n; i ++) {
			cin >> a[i];
			if(a[i] > a[last]) {
				for(int j = i - 1; j >= last; j --)
					v.pb(a[j]);
				last = i;
			}
		}
		for(int j = n - 1; j >= last; j --)
			v.pb(a[j]);
		
		reverse(v.begin(), v.end());
		for(int i = 0; i < n; i ++)
			cout << v[i] << ' ';
		cout << '\n';
	}
}