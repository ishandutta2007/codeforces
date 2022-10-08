#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define N 70010

map<string, int> A;
int n;
set<string> b[N];
string a[N];

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
		for (int j = 0; j < 9; j ++)
			for (int k = j+1; k <= 9; k ++)
				b[i].insert(a[i].substr(j, k-j));
		for (set<string>::iterator j = b[i].begin(); j != b[i].end(); j ++)
			A[*j] ++;
	}
	for (int i = 0; i < n; i ++) {
		string s = a[i];
		for (set<string>::iterator j = b[i].begin(); j != b[i].end(); j ++)
			if (j->length() < s.length() && A[*j] == 1) s = *j;
		cout << s << endl;
	}
	return 0;
}