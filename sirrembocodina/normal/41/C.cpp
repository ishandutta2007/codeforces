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

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define int64 long long       
#define ld long double
#define pi 3.1415926535897932
#define all(a) a.begin(), a.end()

string s, t;

int main() {
	cin >> s;
	int ind = 1;
	t = "";
	t += s[0];
	while (1) {
		if (s[ind] == 'a' && s[ind + 1] == 't') {
			t += '@';
			break;
		} else {
			t += s[ind];
			ind++;
		}
	}
	for (int i = ind + 2; i < s.size(); i++) {
		t += s[i];
	}
	s = t;
	int i = 1;
	t = "";
	t += s[0];
	while (i < s.size() - 3) {
		if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't') {
			t += '.';
			i = i + 3;
		} else {
			t += s[i];
			i++;
		}
	}
	for (int j = i; j < s.size(); j++) {
		t += s[j];
	}
	cout << t;
}