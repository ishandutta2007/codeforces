#include <bits/stdc++.h>
using namespace std;

const int N = 2e5L + 11;

int s[N], t[N];

int main() {
	ios :: sync_with_stdio(0);
	int a, b, k; cin >> a >> b >> k;
	
	bool f = 0;
	if(k == 0) {
		for(int i = 1; i <= b; i ++)
			s[i] = t[i] = 1;
		f = 1;
	} else if(a > 0 && b > 1 && k <= a + b - 2) {
		s[1] = t[1] = 1;
		s[2] = 1;
		t[k + 2] = 1;
		
		int same = b - 2;
		for(int i = 1; i <= a + b; i ++)
			if(s[i] == 0 && t[i] == 0 && same) {
				same --;
				s[i] = t[i] = 1;
			}
		
		f = 1;
	}
	
	if(f) {
		cout << "Yes\n";
		for(int i = 1; i <= a + b; i ++)
			cout << s[i];
		cout << '\n';
		for(int i = 1; i <= a + b; i ++)
			cout << t[i];
		cout << '\n';
	} else
		cout << "No\n";
}