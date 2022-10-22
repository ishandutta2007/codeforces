#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
string s, t;
set<string> all;

void out()
{
	bool f = 0;
	for (const string& s : all) {
		cout << s << (f ? "\n" : " ");
		f = 1;
	}
}

int main() {
	cin >> s;
	all.insert(s);
	cin >> t;
	all.insert(t);
	cin >> n;

	cout << s << " " << t << "\n";
	while (n--) {
		string a, b;
		cin >> a >> b;
		all.erase(a);
		all.insert(b);
		out();
	}

	return 0;
}