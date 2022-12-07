#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#include<cstring>
#define mp make_pair
#define pb push_back      
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ll<<(x))
#define buli(x) __builtin_popcountll(x)
#define M 1000000007
#define N 211111

#define TASK "1"

using namespace std;
typedef pair<int,int> pt;

vector<int> ans[11];
long long fu[11];

int gr(vector<int> a , vector<int> b) {
	if (a.size() > b.size()) return 1;
	if (a.size() < b.size()) return 0;
	return a > b;
}

void go(long long o, vector<int> a) {
	if (o > fu[9]) return;
	sort(a.rbegin(), a.rend());
	for (int i = 2; i <= 9; i++) if (o == fu[i]) {
		if (gr(a, ans[i])) ans[i] = a;
	}

	for (int i = 2; i <= 9; i++) {
		vector<int> b = a;
		b.pb(i);
		go(o * fu[i], b);
	}
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	fu[0] = 1;
	for (int i = 1; i <= 9; i++) fu[i] = fu[i - 1] * i;
	vector<int> a;

	for (int i = 2; i <= 9; i++) {
		vector<int> t;
		t.pb(i);
		ans[i] = t;
	}
	go(1, a);

	string s;
	cin >> s;
	cin >> s;
	vector<int> out;
	for (int i = 0; i < s.size(); i++) if (s[i] > '1') {
//		cout << ans[s[i] - '0'].size() << endl;
		for (int j = 0; j < ans[s[i] - '0'].size(); j++) out.pb(ans[s[i] - '0'][j]);
	}
	sort(out.rbegin(), out.rend());
	for (int i = 0; i < out.size(); i++) cout << out[i];
	cout << endl;
	return 0;
}