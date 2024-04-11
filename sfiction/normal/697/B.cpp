#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

int main(){
	string s;
	cin >> s;
	int e = s.find_first_of('e');
	string a(s.begin(), s.begin() + e);
	int b;
	sscanf(s.c_str() + e + 1, "%d", &b);
	for (int i = 1; i <= b; ++i){
		if (i + 1 >= a.size())
			a.push_back('0');
		swap(a[i], a[i + 1]);
	}
	while (a.back() == '0')
		a.pop_back();
	if (a.back() == '.')
		a.pop_back();
	puts(a.c_str());
	return 0;
}