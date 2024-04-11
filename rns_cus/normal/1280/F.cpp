#include <bits/stdc++.h>
using namespace std;

#define N 111

int K, m, nxt_l[N], nxt_r[N], prv_l[N], prv_r[N], a[N], b[N], pos_l[N], pos_r[N], pos[N], rnk[N];
char s[10];

bool le[N], ri[N];

void push_l(int k) {
    for (int i = 1; i <= m; i ++) b[i] = a[pos_l[i]];
    for (int i = 1; i <= m; i ++) pos[a[pos_l[i]] = b[(i-k+m-1)%m+1]] = pos_l[i];
    for (int i = 0; i < k; i ++) putchar('L');
}

void push_r(int k) {
    for (int i = 1; i <= m; i ++) b[i] = a[pos_r[i]];
    for (int i = 1; i <= m; i ++) pos[a[pos_r[i]] = b[(i-k+m-1)%m+1]] = pos_r[i];
    for (int i = 0; i < k; i ++) putchar('R');
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &K); m = 2 * K + 1;
        for (int i = 1; i <= 4 * K + 2; i ++) {
            scanf("%s", s);
            if (s[0] == 'E') a[i] = 0;
            else a[i] = atoi(s);
            le[i] = ri[i] = 0;
            if (a[i] >= 3 * K + 2) a[i] ++;
        }


        bool can = 0;
        for (int i = 1; i <= 4 * K + 2; i ++) {
            if (!a[i]) continue;
            for (int j = 1; j < i; j ++) {
                if (!a[j]) continue;
                if (a[j] > a[i]) can ^= 1;
            }
        }
        if (can) {
            puts("SURGERY FAILED");
            continue;
        }
        puts("SURGERY COMPLETE");


        for (int i = 1; i <= K; i ++) nxt_l[i] = i + 1;
        nxt_l[K+1] = 3 * K + 1;
        for (int i = 3 * K + 1; i > 2 * K + 2; i --) nxt_l[i] = i - 1;
        nxt_l[2*K+2] = 1;
        for (int i = m; i > K + 1; i --) nxt_r[i] = i - 1;
        nxt_r[K+1] = 3 * K + 3;
        for (int i = 3 * K + 3; i <= 4 * K + 1; i ++) nxt_r[i] = i + 1;
        nxt_r[4*K+2] = m;

        for (int i = 1, st = 1; i <= m; i ++) {
            pos_l[i] = st; rnk[st] = i;
            le[st] = 1; prv_l[nxt_l[st]] = st, st = nxt_l[st];
        }
        for (int i = 1, st = m; i <= m; i ++) {
            pos_r[i] = st; rnk[st] = i;
            ri[st] = 1; prv_r[nxt_r[st]] = st, st = nxt_r[st];
        }


        int r = 0;
        for (r = 1; r <= 4 * K + 2; r ++) if (a[r] == 0) break;
        if (le[r]) {
            int c = (r - 1) % m + 1;
            while (c <= K) putchar('r'), swap(a[r], a[r+1]), c ++, r ++;
            if (r == K + 1) putchar('d'), swap(a[r], a[r+m]);
        }
        else {
            int c = (r - 1) % m + 1;
            while (c > K + 1) putchar('l'), swap(a[r], a[r-1]), c --, r --;
            if (r == K + 1) putchar('d'), swap(a[r], a[r+m]);
        }
        for (int i = 1; i <= 4 * K + 2; i ++) if (a[i]) pos[a[i]] = i;

        r = pos[K];
        if (!le[r]) {
            push_r((rnk[K+1] - rnk[r] + m) % m);
            assert(pos[K] == K + 1);
        }
        for (int i = K; prv_l[i] != 3 * K + 1; i = prv_l[i]) {
            int u = prv_l[i], r = pos[u];
            if (r == prv_l[pos[i]]) continue;
            if (le[r]) {
                push_l((rnk[K+1] - rnk[r] + m) % m);
                push_r(m - 1);
                push_l((rnk[3*K+1] - rnk[pos[i]] + m) % m);
                push_r(1);
            }
            else {
                push_l((rnk[3*K+1] - rnk[pos[i]] + m) % m);
                push_r((rnk[K+1] - rnk[r] + m) % m);
            }
        }
        if (pos[K] != K) push_l((rnk[K] - rnk[pos[K]] + m) % m);



        r = pos[K+2];
        if (!ri[r]) {
            int c = (rnk[K+1] - rnk[r] + m) % m;
            push_l(c);
            push_r(1);
            push_l((m - c) % m);
        }
        for (int i = K + 2; prv_r[i] != 3 * K + 3; i = prv_r[i]) {
            int u = prv_r[i], r = pos[u];
            if (r == prv_r[pos[i]]) continue;
            if (ri[r]) {
                push_r((rnk[K+1] - rnk[r] + m) % m);
                push_l(m - 1);
                push_r((rnk[3*K+3] - rnk[pos[i]] + m) % m);
                push_l(1);
            }
            else {
                push_r((rnk[3*K+3] - rnk[pos[i]] + m) % m);
                int c = (rnk[K+1] - rnk[r] + m) % m;
                push_l(c);
                push_r(1);
                push_l((m - c) % m);
            }

        }
        if (pos[K+2] != K + 2) push_r((rnk[K+2] - rnk[pos[K+2]] + m) % m);
        while (pos[K+1] != K + 1) {
            push_l(m - 1), push_r(m - 1), push_l(1), push_r(1);
        }


//        cout << endl << "here " << endl;
//        for (int i = 1; i <= m; i ++) cout << a[i] << ' '; cout << endl;
//        for (int i = 1; i <= m; i ++) cout << a[m+i] << ' ';cout << endl;



        for (int i = K + 1; i <= 2 * K; i ++) putchar('r');
        puts("");
        putchar('L'); putchar(' ');
        putchar('u'); for (int i = 0; i < K; i ++) putchar('l');
        putchar('d'); for (int i = 0; i < K; i ++) putchar('r');
        puts("");

        putchar('R'); putchar(' ');
        putchar('u'); for (int i = 0; i < K; i ++) putchar('r');
        putchar('d'); for (int i = 0; i < K; i ++) putchar('l');
        puts("");
        puts("DONE");
    }

    return 0;
}