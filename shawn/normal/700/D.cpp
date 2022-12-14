//#include <bits/stdc++.h>

#include <cstdio>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define N 100010

int c[N] , a[N] , b[N] , ans[N] , number[N] , appear[N] , num[N] , pos[N];
int n , m , l , r , tot , block;

int read () {
	int x = 0 , f = 1 , c = getchar();
	for ( ; c > '9' || c < '0' ; c = getchar() ) f = c == '-' ?-1 :1;
	for ( ; c >= '0' && c <= '9' ; c = getchar() ) x = x * 10 + c - 48;
	return x * f;
}

struct Que {
	int l , r , id;
	bool operator < (const Que &t) const{
		return (pos[l] == pos[t.l] && r < t.r) || pos[l] < pos[t.l];
	}
}q[N];

void update (int x , int y) {
	number[appear[x]]-- , appear[x] += y , number[appear[x]] ++;
}

int build() {
	int ff = 0 , sum = 0;
	priority_queue <int , vector <int> , greater <int> > Q;
	for (int i = 1 ; i <= tot ; i ++) if (appear[c[i]] > block) Q.push(appear[c[i]]);
	for (int i = 1 ; i <= block ; i ++) num[i] = number[i];
	for (int i = 1 ; i <= block ; i ++) {
		if (num[i]) {
			if(ff) {
				num[i] --;
				if (i + ff > block) Q.push((i + ff));
				else num[i + ff] ++;
				sum += i + ff;
				ff = 0;
			} 
			if (num[i] & 1) num[i] -- , ff = i;
			sum += num[i] * i;
			if (i + i > block) for (int k = 1 ; k <= (num[i] >> 1) ; k ++) Q.push(i + i);
			else num[i + i] += (num[i] >> 1);
		}
	}
	if (ff) Q.push(ff);
	while (Q.size() > 1) {
		int x , y;
		x = Q.top() , Q.pop();
		y = Q.top() , Q.pop();
		sum += x + y;
		Q.push((x + y));
	}
	return sum;
}

int main() {
	n = read() , block = sqrt(n) * 11 / 8 + 1;
	for (int i = 1 ; i <= n ; i ++) {
		b[a[i] = read()] ++;
		pos[i] = (i - 1) / block + 1;
		if (b[a[i]] == block) c[++ tot] = a[i];
	}
	m = read();
	for (int i = 1 ; i <= m ; i ++) q[q[i].id = i].l = read() , q[i].r = read();
	sort(q + 1 , q + m + 1);
	l = 1 , r = 0;
	for (int i = 1 ; i <= m ; i ++) {
		while (l < q[i].l) update(a[l ++] , -1);
		while (q[i].l < l) update(a[-- l] , 1);
		while (q[i].r < r) update(a[r --] , -1);
		while (r < q[i].r) update(a[++ r] , 1);
		ans[q[i].id] = build();
	}
	for (int i = 1 ; i <= m ; i ++) printf("%d\n" , ans[i]);
	return 0;
}