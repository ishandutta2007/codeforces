#include <bits/stdc++.h>

#define debug (0)

void read(int &n){
    n = 0;
    char ch;
    while (!isdigit(ch = getchar()))
        ;
    n = ch - '0';
    while (isdigit(ch = getchar())){
        n = n * 10 + ch - '0';
    }
}

const int max_N = 1010;

int n, l, k;
char s[max_N * max_N];
char ans[max_N][max_N];
int cnt[300];
char wjj[max_N];
char tmp[max_N][max_N];
int Q[max_N];

void bl() {
    std::sort(s, n * l + s);
    bool flag = false;
    do {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < l; ++j) {
                tmp[i][j] = s[i * l + j];
            }
            Q[i] = i;
        }
        std::sort(Q, n + Q, [&](const int &a, const int &b) {
            return strcmp(tmp[a], tmp[b]) < 0;
        });
        if (!flag || strcmp(wjj, tmp[Q[k - 1]]) > 0) {
            memcpy(wjj, tmp[Q[k - 1]], sizeof(wjj));
            flag = true;
        }
    } while (std::next_permutation(s, n * l + s));

    std::sort(s, n * l + s);
    do {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < l; ++j) {
                tmp[i][j] = s[i * l + j];
            }
            Q[i] = i;
        }
        std::sort(Q, n + Q, [&](const int &a, const int &b) {
            return strcmp(tmp[a], tmp[b]) < 0;
        });
        if (strcmp(wjj, tmp[Q[k - 1]]) == 0) {
            return;
        }
    } while (std::next_permutation(s, n * l + s));
}

int main () {
    srand((unsigned)time(nullptr));
    if (debug) {
        n = rand() % 5 + 1, l = rand() % 3 + 1, k = rand() % n + 1;
        printf("%d %d %d\n", n, l, k);
        for (int i = 0; i < n * l; ++i) {
            s[i] = rand() % 5 + 'a';
        }
    } else {
        scanf("%d%d%d", &n, &l, &k);
        scanf("%s", s);
    }
    std::sort(s, n * l + s);
    for (int i = k; i < n; ++i) {
        for (int j = 0; j < l; ++j) {
            ans[i][j] = s[i * l + j];
        }
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < l; ++j) {
            ++cnt[s[i * l + j]];
        }
    }
    int begin = 0;
    for (int i = 0; i < l; ++i) {
        char t = 'a';
        for (int j = begin; j < k; ++j) {
            while (!cnt[t]) ++t;
            ans[j][i] = t;
            --cnt[t];
        }
        int end;
        for (end = begin; ans[end][i] < ans[k - 1][i]; ++end);

        for (int p = end - 1; p >= begin; --p) {
            t = 'z';
            for (int j = i + 1; j < l; ++j) {
                while (!cnt[t]) --t;
                ans[p][j] = t;
                --cnt[t];
            }
        }

        begin = end;
    }
    if (debug) {
        bl();
        if (strcmp(ans[k - 1], wjj) != 0) {
            puts("NO");
            printf("should be %s\n", wjj);
            for (int i = 0; i < n; ++i) {
                puts(tmp[Q[i]]);
            }
            printf("----\n");
        }
    }
    for (int i = 0; i < n; ++i) {
        puts(ans[i]);
    }
    return 0;
}