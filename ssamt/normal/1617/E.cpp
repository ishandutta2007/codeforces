#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	priority_queue<int> pq;
	set<int> visited;
	map<int, vector<int>> len;
	int answer = 0;
	int u, v;
	for(i=0; i<n; i++) {
		pq.push(a[i]);
		len[a[i]] = {0, i};
		visited.insert(a[i]);
	}
	while(true) {
		int num = pq.top();
		//printf("%d\n", num);
		pq.pop();
		if(pq.empty()) {
			break;
		}
		for(i=0; (1<<i)<num; i++);
		int next = (1<<i)-num;
		if(!visited.count(next)) {
			pq.push(next);
			visited.insert(next);
			len[next] = {len[num][0]+1, len[num][1]};
		} else {
			if(len[num][0]+1+len[next][0] > answer) {
				answer = len[num][0]+1+len[next][0];
				u = len[num][1];
				v = len[next][1];
			}
			if(len[num][0]+1 > len[next][0]) {
				len[next][0] = len[num][0]+1;
				len[next][1] = len[num][1];
			}
		}
	}
	printf("%d %d %d\n", u+1, v+1, answer);
}