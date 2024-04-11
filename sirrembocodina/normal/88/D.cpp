#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <list>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
        
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = n - 1 ; i >= 0 ; i--)
#define forv(i, a) for (int i = 0; i < (int)(a.size()); i++)
#define forab(i, a, b) for (int i = a; i < (int)(b); i++)
#define fordab(i, a, b) for (int i = b - 1; i >= (int)(a); i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()
#define eps 0.0000001

typedef long long int64;       
typedef long double ld;

string s, t;
map<string, int> m;

int main() {
//	freopen("input.txt", "rt", stdin);
//	freopen("output.txt", "wt", stdout);
	m["void"] = 0;
	int n;
	cin >> n;
	forn (q, n) {
		cin >> s;
		if (s.size() == 7) {
			cin >> s;
			int i = 0;
			for (; s[i] == '&'; i++);
			int j = i;
			for (; j < (int)(s.size()) && s[j] != '*'; j++);
			t = s.substr(i, j - i);
			i = s.size() - j - i;
			cin >> s;
//			cerr << i << " " << s << endl;
			if (m.find(t) == m.end() || m[t] == -1 || m[t] + i < 0) {
				m[s] = -1;
			} else {
				m[s] = m[t] + i;
			}
		} else {
			cin >> s;
			int i = 0;
			for (; s[i] == '&'; i++);
			int j = i;
			for (; j < (int)(s.size()) && s[j] != '*'; j++);
			t = s.substr(i, j - i);
			i = s.size() - j - i;
//			cerr << i << " " << s << endl;
			if (m.find(t) == m.end() || m[t] == -1 || m[t] + i < 0) {
				cout << "errtype";
			} else {
				cout << "void";
				forn (j, m[t] + i) {
					cout << '*';
				}
			}
			cout << endl;
		}
	}
}