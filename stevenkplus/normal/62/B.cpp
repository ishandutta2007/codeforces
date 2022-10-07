#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef stringstream ss;
typedef priority_queue<pii, vector<pii>, greater<pii> > PQ;
typedef pair<pii, int> circ;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define clr(t,v) memset((t),(v),sizeof(t))
#define p(a) cout << #a << ": " << a << endl;

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define dwn(i,n) for(int i=(n);--i>=0;)
#define repr(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define dwnr(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)
#define repi(i,a) for(__typeof((a).begin()) i=(a).begin(),_##i=(a).end();i!=_##i;++i)
#define dwni(i,a) for(__typeof((a).rbegin()) i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)
const int inf = 1 << 30;
char buf[1000];
string nextLine(int length = 100) {
	cin.getline(buf, length);
	string s(buf);
	return s;
}
string next(int length = 100) {
	string tmp;
	cin >> tmp;
	return tmp;
}

int nextInt() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}
const int MAXC = 26;
int c(char ch) {
	return ch - 'a';
}
vi occurences[MAXC];
int find(int i, char ch) {
	vi &v = occurences[c(ch)];
	int top = sz(v);
	if (top == 0)
		return -1;
	int low = 0;
	while (low < top) {
		int mid = (low + top) / 2;
		if (v[mid] == i) {
			return v[mid];
		}
		if (v[mid] > i)
			top = mid;
		else
			low = mid + 1;
	}
	low--;

	if (low >= 0 && (top == sz(v) || i - v[low] < v[top] - i))
		return v[low];
	else
		return v[top];
}
int main() {
	int n = nextInt(), l = nextInt();
	string s = next();
	rep(i,l) {
		occurences[c(s[i])].pb(i);
	}
	rep(i,MAXC) {
		sort(occurences[i].begin(), occurences[i].end());
	}
	rep(i,n) {
		string s = next();
		ll sum = 0;
		int size = sz(s);
		rep(j,size) {
			char ch = s[j];
			int k = find(j, ch);
			if (k == -1)
				sum += size;
			else
				sum += abs(k - j);
		}
		cout << sum << "\n";
	}
}