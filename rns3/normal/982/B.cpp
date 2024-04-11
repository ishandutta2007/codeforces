#include <bits/stdc++.h>

using namespace std;



#define N 404040



char s[N];

int n, a[N];



typedef pair <int, int> pii;

priority_queue <pii> pq, pq_;



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), pq.push(make_pair(-a[i], i));

	scanf("%s", s);

	for (int i = 0; i < n * 2; i ++) {

		if (s[i] == '0') {

			int j = pq.top().second;

			printf("%d ", j);

			pq.pop();

			pq_.push(make_pair(a[j], j));

		}

		else {

			int j = pq_.top().second;

			printf("%d ", j);

			pq_.pop();

		}

	}



	return 0;

}