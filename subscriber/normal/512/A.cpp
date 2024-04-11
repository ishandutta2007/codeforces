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

int n;
string s[111];
int le[111][111];
int ne[111];
int was[111];

vector<int> order;

void go(int x) {
	if (was[x]) return;
	was[x] = 1;
	for (int i = 0; i < 27; i++) if (le[i][x]) go(i);
	order.pb(x);
}

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n;
	int ml = 0;
	for (int i= 0; i < n; i++) {
		cin >> s[i];
		ml = max(ml, (int)s[i].size());
	}		

	for (int i = 0; i < n; i++) while (s[i].size() < ml) s[i] += (char)('z' + 1);

	for (int i = 0; i < n - 1; i++) ne[i] = 0;

	for (int i = 0; i < ml; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (!ne[j] && s[j][i] != s[j + 1][i]) {
				le[s[j][i] - 'a'][s[j + 1][i] - 'a'] = 1;
				ne[j] = 1;
			}
		}
	}
	for (int i = 0; i < 26; i++) le[26][i] = 1;

	for (int i = 0; i < 27; i++) if (!was[i]) go(i);

	int im = 0;
	for (int i = 0; i < 27; i++) for (int j = i + 1; j < 27; j++) if (le[order[j]][order[i]]) im = 1;
	if (im) {
		puts("Impossible");
		return 0;
	}

	for (int i = 0; i < 27; i++) if (order[i] != 26) putchar(order[i] + 'a');
	puts("");

	return 0;
}