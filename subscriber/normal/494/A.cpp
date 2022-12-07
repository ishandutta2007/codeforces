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

char s[N];


int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	gets(s);
	int n = strlen(s);

	int tot = 0;
	int last = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') tot++; else {
			if (s[i] == '#') last = i;
			tot--;
		}			
	}		
	if (tot < 0) {
		puts("-1");
		return 0;
	}

	vector<int> ans;
	int bal = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			bal++;
		} else if (s[i] == ')' || s[i] == '#') {
			if (s[i] == ')') bal--; else {
				int v = 1;
				if (i == last) v += tot;
				ans.pb(v);
				bal -= v;

			}
			if (bal < 0) {
				puts("-1");
				return 0;
			}
		}
	}
	if (bal != 0) {
		puts("-1");
		return 0;
	}
	for (int i =0; i< ans.size(); i++) printf("%d\n", ans[i]);
	return 0;
}