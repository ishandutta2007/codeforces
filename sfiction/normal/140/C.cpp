/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 140C
 */
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int MAXN = (1E5 / 3) + 100;

map<int, int> cnt;

priority_queue<pair<int, int> > ball;

int out[MAXN][3];

int main(){
	int n;

	scanf("%d", &n);
	for (int t,i=0;i<n;++i){
		scanf("%d", &t);
		if (cnt.find(t) != cnt.end())
			++cnt[t];
		else
			cnt[t] = 1;
	}

	for (map<int, int>::iterator p = cnt.begin(); p != cnt.end(); ++p)
		ball.push(make_pair(p->second, p->first));

	pair<int, int> a[3];
	int ans = 0;
	for (; ball.size() >= 3; ++ans){
		for (int i=0;i<3;++i){
			a[i] = ball.top();
			out[ans][i] = a[i].second;
			ball.pop();
		}

		sort(out[ans], out[ans] + 3);
		
		for (int i=0;i<3;++i)
			if (--a[i].first)
				ball.push(a[i]);
	}

	printf("%d\n", ans);
	for (int i=0;i<ans;++i)
		printf("%d %d %d\n", out[i][2], out[i][1], out[i][0]);

	return 0;
}