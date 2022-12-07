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
#define M 1000000007
#define N 111111
using namespace std;
typedef pair<int,int> pt;

int n, m;
int bad[N];
int first[N], used[N];
int x[N];
char t[N];
int q1, q2;

int main(){
//	freopen("1.in","r",stdin);	
//	freopen("1.out","w",stdout);
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%c %d\n", &t[i], &x[i]);
		used[x[i]] = 1;
	}
	int kol = 0, kol2 = 0;
	for (int i = 0; i < m; i++) {
		if (first[x[i]] == 0 && t[i] == '-') q1 = 1, kol++;
		first[x[i]] = 1;
	}
	for (int i = 0; i <= n; i++) first[i] = 0;
	for (int i = m - 1; i >= 0; i--) {
		if (first[x[i]] == 0 && t[i] == '+') q2 = 1, kol2++;
		first[x[i]] = 1;
        }
        set<int> only;
	for (int i = 0; i < m; i++) {
		if (t[i] == '+' && kol == 0) only.insert(x[i]);
		if (t[i] == '+' && kol > 0) bad[x[i]] = 1;
		if (t[i] == '+') kol++; else kol--;
	}
	for (int i = m - 1; i >= 0; i--) {
		if (t[i] == '-' && kol2 == 0) only.insert(x[i]);
		if (t[i] == '-' && kol2 > 0) bad[x[i]] = 1;	
		if (t[i] == '-') kol2++; else kol2--;
		
	}
	int h = 2;	
	for (set<int> :: iterator it = only.begin(); it != only.end(); it++) {
		int x = *it;
		for (int i = 1; i <= n;i ++) if (i != x) bad[i] = 1;
		h--;
		if (h < 0) break;
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++) if (!bad[i] || used[i] == 0) ans.pb(i);
	cout << ans.size() << endl;
	if (ans.size()) {
		for (int i = 0; i < ans.size() - 1; i++) printf("%d ", ans[i]);
		cout << ans.back() << endl;
	}
	return 0;
}