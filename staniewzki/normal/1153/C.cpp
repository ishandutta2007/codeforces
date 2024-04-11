#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define V vector
#define EB emplace_back
#define ST first
#define ND second

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n;
	cin >> n;
	string str;
	cin >> str;

	auto err = [](){ cout << ":(\n"; exit(0); };

	if(n % 2 == 1) err();

	if(str[0] == ')') err();
	str[0] = '(';

	if(str[n - 1] == '(') err();
	str[n - 1] = ')';

	int x = n / 2;
	for(int i = 0; i < n; i++)
		if(str[i] == '(') x--;

	for(int i = 0; i < n; i++)
	{
		if(str[i] == '?' && x != 0)
			str[i] = '(', x--;
		else if(str[i] == '?')
			str[i] = ')';
	}

	int a = 0;
	for(int i = 0; i < n; i++)
	{
		if(str[i] == '(') a++;
		else a--;

		if(a < 0) err();
		if(a == 0 && i != n - 1) err();
	}

	if(a != 0) err();

	cout << str << "\n";
}