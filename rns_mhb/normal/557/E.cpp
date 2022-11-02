#include <bits/stdc++.h>
using namespace std;

#define N 10010

char s[N];
int k, m, n, st, en, lcp[N], sa[N], wa[N], x[N], y[N], wv[N];

inline int cmp(int *r, int a, int b, int l) {return r[a] == r[b] && r[a + l] == r[b + l];}

void buildsa() {
    m = 2;
    for(int i = 0; i < n; i ++) wa[x[i] = (s[i] - 'a' + 1)] ++;
    wa[2] += wa[1];
    for(int i = n - 1; i >= 0; i --) sa[-- wa[x[i]]] = i;
    for (int j = 1,p = 1; p < n; j *= 2, m = p) {
        /*for(int i = 0; i < n; i ++) printf("%d ", sa[i]);
        puts("sa");
        for(int i = 0; i < n; i ++) printf("%d ", x[i]);
        puts("xxx");*/
		p = 0;
		for (int i = n - j; i < n; i ++) y[p ++] = i;
		for (int i = 0; i < n; i ++) if (sa[i] >= j) y[p ++] = sa[i] - j;
		/*for (int i = 0; i < n; i ++) printf("%d ", y[i]);
		puts("yyy");*/
		for (int i = 0; i < n;i ++) wv[i] = x[y[i]];
		for (int i = 0; i <= m; i ++) wa[i] = 0;
		for (int i = 0; i < n; i ++) wa[wv[i]] ++;
		for (int i = 1; i <= m; i ++) wa[i] += wa[i - 1];
		for (int i = n - 1; i >= 0 ; i --) sa[-- wa[wv[i]]] = y[i];
		//for(int i = 0; i < n; i ++) printf("%d ", sa[i]);
        //puts("");
		swap(x, y), p = 1, x[sa[0]] = 1;
		for (int i = 1; i < n; i ++) x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p: ++ p;
	}
	return;
}

void calclcp() {
    lcp[0] = 0;
	for (int i = 0; i < n; i ++) x[sa[i]] = i;
	for (int h = 0, i = 0; i < n; i ++) if (x[i] > 0) {
		int j = sa[x[i] - 1];
		while (s[i + h] == s[j + h]) ++ h;
		lcp[x[i]] = h;
		if (h > 0) h --;
	}
}

bool test(int f, int l) {
    if(s[f] != s[l]) return 0;
    return 1;
}

queue <int> pal[N];

int main() {
    //freopen("ksh.in", "r", stdin);

    scanf("%s%d", s, &k);
    n = strlen(s);
    for (int i = 0; i < 2 * n; i ++) {
        st = i / 2;
        en = (i + 1) / 2;
        while (st >= 0 && en < n && test(st, en)) {
            pal[st].push(en);
            st -= 2;
            en += 2;
        }
        st = i / 2 - 1;
        en = (i + 3) / 2;
        while (st >= 0 && en < n && test(st, en)) {
            pal[st].push(en);
            st -= 2;
            en += 2;
        }
    }
    /*for(int i = 0; i < n; i ++) {
        while(!pal[i].empty()) {
            printf("%d %d\n", i, pal[i].front());
            pal[i].pop();
        }
    }*/
    buildsa();
    calclcp();
    //for (int i = 0; i < n; i ++) printf("%d ", sa[i]);
    //puts("");
    //for(int i = 1; i < n; i ++) printf("%d ", lcp[i]);
    int alive = 0, point = 0;
    while(pal[sa[alive]].empty()) alive ++;
    point = alive;
    //printf("%d %d", alive, point);
    while(k --) {
        st = sa[point];
        en = pal[st].front();
        pal[st].pop();
        if(point < n - 1 && lcp[point + 1] > en - st) point ++;
        else {
            while(pal[sa[alive]].empty() && alive < n) alive ++;
            point = alive;
        }
    }
    for(int i = st; i <= en; i ++) printf("%c", s[i]);
}