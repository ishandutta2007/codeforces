#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define maxn 222222

set<int> S;
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > H;
int i, j, k, n, a[maxn], nl, nr, sz, aa, bb, u[maxn], o;
pair<int, pair<int, int> > pp;
set<pair<int, int> >::iterator it;
char s[maxn];

int next(int k){
	set<int>::iterator it = S.find(k);
	++it;
	if (it == S.end()) return -1; else return *it;
}

int pred(int k){
	set<int>::iterator it = S.find(k);
	if (it == S.begin()) return -1; else{
		--it;
		return *it;
	}
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	gets(s);
	gets(s);
	for(i = 0; i<n; i++) if (s[i] == 'B') ++aa; else ++bb;
	sz = min(aa, bb);
	printf("%d\n", sz);
	for(i = 0; i<n; i++) scanf("%d", &a[i]);
	for(i = 1; i<=n; i++) S.insert(i);
	for(i = 1; i<n; i++) if (s[i-1] != s[i]) H.push(make_pair(abs(a[i]-a[i-1]), make_pair(i, i+1)) );
	o = 0;
	while(o!=sz){
		pp = H.top();
		H.pop();
		if (u[pp.second.first]) continue;
		if (u[pp.second.second]) continue;

		printf("%d %d\n", pp.second.first, pp.second.second);

		nl = pred(pp.second.first);
		nr = next(pp.second.second);

		if (nl>-1 && nr>-1 && s[nl-1] != s[nr-1]) H.push(make_pair(abs(a[nl-1]-a[nr-1]), make_pair(nl, nr)));

		S.erase(S.find(pp.second.first));
		S.erase(S.find(pp.second.second));
		u[pp.second.first] = 1;
		u[pp.second.second] = 1;
		++o;
	}
	return 0;
}