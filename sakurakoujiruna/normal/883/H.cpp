#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int mxn = 400006;

char s[mxn];
int c[128];

int n;
vector<char> pa, si;

int main() {
	cin >> n;
	scanf("%s", s);
	
	for (auto i = s; *i; ++i)
		++c[*i];
	
	for (int i = 0; i < 128; ++i) {
		for (int k = 0; k < c[i] / 2; ++k)
			pa.pb(i);
		for (int k = 0; k < c[i] % 2; ++k)
			si.pb(i);
	}
	
	for (int i = 1; i <= n; ++i) if (n % i == 0) {
		if (n / i % 2 == 0) {
			if (si.size()) continue;
			cout << i << endl;
			for (int j = 0; j < i; ++j) {
				deque<char> s;
				for (int k = 0; k + 2 <= n / i; k += 2) {
					char c = pa.back();
					pa.pop_back();
					s.push_back(c);
					s.push_front(c);
				}
				for (auto i : s)
					printf("%c", i);
				printf(" ");
			}
			
		} else {
			if (si.size() > i) continue;
			cout << i << endl;
			for (int j = 0; j < i; ++j) {
				deque<char> s;
				if (si.empty()) {
					char c = pa.back();
					pa.pop_back();
					si.pb(c);
					si.pb(c);
				}
				
				char c = si.back();
				si.pop_back();
				s = {c};
				
				for (int k = 1; k + 2 <= n / i; k += 2) {
					char c = pa.back();
					pa.pop_back();
					s.push_back(c);
					s.push_front(c);
				}
				for (auto i : s)
					printf("%c", i);
				printf(" ");
			}
		}
		break;
	}
	
	puts("");
	
	return 0;
}