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

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	ios::sync_with_stdio(false);
	string t = "CODEFORCES";
	string s;
	cin >> s;

	int ans = 0;
	for (int i = 0; i < t.size(); i++) if (t[i] != s[i]) break; else ans++;

	for (int i = 0; i < t.size(); i++) if (t[t.size() - 1 - i] != s[s.size() - i - 1]) break; else ans++;

	if (ans >= t.size()) puts("YES"); else puts("NO");
	return 0;
}