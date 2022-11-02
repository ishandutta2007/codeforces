#include <bits/stdc++.h>

using namespace std;

#define N 200100

typedef long long LL;

int n, m, nn, mm;
LL a[N], b[N], ans;
char sa[N][10], sb[N][10];
int h[N];
/*
void make_PI() {
	int k = 0;
	m = strlen(S);
	h[1] = 0;
	for (int i = 2; i <= m; i ++) {
		while (k && S[k] != S[i - 1]) k = h[k];
		if (S[k] == S[i - 1]) k ++;
		h[i] = k;
	}
}

void kmp_Matching() {
	int k = 0;
	n = strlen(T);
	for (int i = 1; i <= n; i ++) {
		while (k && S[k] != T[i - 1]) k = h[k];
		if (S[k] == T[i - 1]) k ++;
		if (k == m) {
			printf("Pattern occurs with shift %d\n", i - m + 1);
			k = h[k];
		}
	}
}*/
void run() {
    int k = 0;
    m = mm - 2;
    h[1] = 0;
    for(int i = 2; i <= m; i ++) {
        while(k && (sb[k + 2][0] != sb[i + 1][0] || b[k+2] != b[i + 1])) k = h[k];
        if(sb[k+2][0] == sb[i + 1][0] && b[k+2] == b[i + 1]) k ++;
        h[i] = k;
    }

    k = 0;
    for(int i = 1; i < nn; i ++) {
        while(k && (sb[k+2][0] != sa[i][0] || b[k+2] != a[i])) k = h[k];
        if(sb[k+2][0] == sa[i][0] && b[k+2] == a[i]) k ++;
        if(k == m) {
            if(i > m) {
                if(sb[1][0] == sa[i-m][0] && sb[mm][0] == sa[i+1][0] && b[1] <= a[i-m] && b[mm] <= a[i+1]) ans ++;
            }
            k = h[k];
        }
    }
    printf("%I64d\n", ans);
}

int main() {
    //freopen("in.txt", "r",stdin);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) {
        scanf("%I64d-%s\n", &a[i], sa[i]);
        if(nn && sa[i][0] == sa[nn][0]) {
            a[nn] += a[i];
        } else {
            nn ++;
            a[nn] = a[i]; sa[nn][0] = sa[i][0];
        }
    }
    for(int i = 1; i <= m; i ++) {
        scanf("%I64d-%s\n", &b[i], sb[i]);
        if(mm && sb[i][0] == sb[mm][0]) {
            b[mm] += b[i];
        } else {
            mm ++;
            b[mm] = b[i]; sb[mm][0] = sb[i][0];
        }
    }
    if(mm == 2) {
        for(int i = 1; i < nn; i ++) {
            if(sa[i][0] == sb[1][0] && sa[i+1][0] == sb[2][0] && a[i] >= b[1] && a[i+1] >= b[2]) ans ++;
        }
        printf("%I64d\n", ans);
        return 0;
    }
    if(mm == 1) {
        for(int i = 1; i <= nn; i ++) {
            if(sa[i][0] == sb[1][0] && a[i] >= b[1]) ans += a[i] - b[1] + 1;
        }
        printf("%I64d\n", ans);
        return 0;
    }
    run();
    return 0;
}