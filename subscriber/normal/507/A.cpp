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

int n, k;
pair<int, int> a[N];

int main(){
//	freopen(TASK".in","r",stdin);	
//	freopen(TASK".out","w",stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) scanf("%d", &a[i].F), a[i].S = i;
	sort(a,a + n);
	
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		if (a[i].F > k) break;
		ans.pb(a[i].S);
		k -= a[i].F;
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i] + 1);
		if (i == ans.size()) puts(""); else putchar(' ');
	}

	return 0;

}