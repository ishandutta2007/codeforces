#pragma comment(linker, "/STACK:100000000")
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex < double > cd;
 
const bool db = false;
 
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define sd second
#define fs first
 
#define inf 1000000007
#define nmax 200010
#define mmax 400010
#define eps 1e-7

int n, h[2010];
vector < int > cnt[2010];
vector < int > bg2, bg3;
int mark[2010];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("message.in", "r", stdin); freopen("message.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> h[i];
		cnt[h[i]].pb(i);
	}
	for(int i = 1; i <= 2000; ++i)
		if(cnt[i].size() >= 3)
			bg3.pb(i);
		else if(cnt[i].size() == 2)
			bg2.pb(i);
	vector < int > ans[3];
	if(bg3.size() >= 1) {
		int ok = 0;
		for(int i = 1; i <= 2000; ++i)
			if(cnt[i].size() >= 3 && !ok) {
				ans[0].pb(cnt[i][0]); ans[0].pb(cnt[i][1]); ans[0].pb(cnt[i][2]);
				ans[1].pb(cnt[i][1]); ans[1].pb(cnt[i][0]); ans[1].pb(cnt[i][2]);
				ans[2].pb(cnt[i][2]); ans[2].pb(cnt[i][1]); ans[2].pb(cnt[i][0]);
				for(int j = 3; j < cnt[i].size(); ++j)
					ans[0].pb(cnt[i][j]), ans[1].pb(cnt[i][j]), ans[2].pb(cnt[i][j]);
				ok = 1;
			} else
				for(int j = 0; j < cnt[i].size(); ++j)
					ans[0].pb(cnt[i][j]), ans[1].pb(cnt[i][j]), ans[2].pb(cnt[i][j]);
	} else if(bg2.size() >= 2) {
		int ok = 0;
		for(int i = 1; i <= 2000; ++i)
			if(cnt[i].size() == 2 && ok < 2) {
				if(ok == 0) {
					ans[0].pb(cnt[i][0]); ans[0].pb(cnt[i][1]);
					ans[1].pb(cnt[i][1]); ans[1].pb(cnt[i][0]);
					ans[2].pb(cnt[i][0]); ans[2].pb(cnt[i][1]);
				} else {
					ans[0].pb(cnt[i][1]); ans[0].pb(cnt[i][0]);
					ans[1].pb(cnt[i][1]); ans[1].pb(cnt[i][0]);
					ans[2].pb(cnt[i][0]); ans[2].pb(cnt[i][1]);
				}
				++ok;
			} else
				for(int j = 0; j < cnt[i].size(); ++j)
					ans[0].pb(cnt[i][j]), ans[1].pb(cnt[i][j]), ans[2].pb(cnt[i][j]);
	} else {
		puts("NO");
		exit(0);
	}
	cout << "YES" << endl;
	for(int j = 0; j < 3; ++j) {
	for(int i = 0; i < n; ++i)
		cout << ans[j][i] << " ";
	cout << endl;
	}
	//while(1);
	return 0;
}