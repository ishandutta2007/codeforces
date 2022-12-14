#include <bits/stdc++.h>

using namespace std;



#define N 101010



set <int> S;

set <int> :: iterator it;

set <pair <int, int> > T;

set <pair <int, int> > :: iterator IT;



int n;

int a[N], id[N];



bool cmp(int i, int j) {

	return a[i] > a[j];

}



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), id[i] = i;

	sort(id + 1, id + n + 1, cmp);

	S.insert(0);

	S.insert(n + 1);

	T.insert(make_pair(n + 1, 0));



	int ans = 1, rlt = a[id[1]] + 1;

	if (n == 1) {

		printf("%d\n", rlt);

		return 0;

	}

	int tot = 1;

	for (int k = 1; k <= n; k ++) {

		int i = id[k];

		it = S.lower_bound(i);

		int ri = *it;

		it --;

		int le = *it;//printf("%d _ %d _ %d\n", le, i, ri);

		S.insert(i);

		T.erase(make_pair(ri - le, le)), tot --;

		if (i < ri - 1) T.insert(make_pair(ri - i, i)), tot ++;

		if (i > le + 1) T.insert(make_pair(i - le, le)), tot ++;



		if (T.empty()) continue;

		IT = T.begin();

		int mn = (*IT).first;

		IT = T.end();

		IT --;

		int mx = (*IT).first;

		//printf("(%d == %d)	%d\n", mn, mx, tot);

		if (mn == mx) {//printf("tot = %d\n", tot);

			if (ans <= tot) ans = tot, rlt = a[id[k+1]] + 1;

		}

	}

	printf("%d\n", rlt);



	return 0;

}