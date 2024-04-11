#include <bits/stdc++.h>
#define sz(x) ((int)((x).size()))
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int MaxN = 300005;

int N, p[MaxN], foo[MaxN], count[MaxN], ans, anscount;
char s[MaxN];
std::vector<int> e[MaxN], c[MaxN];

void go(int i) {
    for (int j : e[i]) if (j != p[i]) {
        p[j] = i;
        c[i].push_back(j);
        go(j);
    }
}
bool cmp(int a, int b) {
    return s[a] < s[b];
}
bool eq(int a, int b) {
    return s[a] == s[b];
}
void merge(int i, int j) {
    int ii = 0, jj = 0;
    std::vector<int> add;
    while (ii < sz(c[i]) && jj < sz(c[j])) {
        if (s[c[i][ii]] < s[c[j][jj]]) {
            ii++;
        } else if (s[c[j][jj]] < s[c[i][ii]]) {
            add.push_back(c[j][jj]);
            count[i] += count[c[j][jj]];
            jj++;
        } else {
            count[i] -= count[c[i][ii]];
            merge(c[i][ii], c[j][jj]);
            count[i] += count[c[i][ii]];
            ii++;
            jj++;
        }
    }
    while (ii < sz(c[i])) {
        ii++;
        // do nothing yay!
    }
    while (jj < sz(c[j])) {
        add.push_back(c[j][jj]);
        count[i] += count[c[j][jj]];
        jj++;
    }
    for (int a : add) c[i].push_back(a);
    std::sort(c[i].begin(), c[i].end(), cmp);
}
void ho(int i) {
    count[i] = 1;
    std::sort(c[i].begin(), c[i].end(), cmp);
    int into = 0;
    for (int j = 0; j < sz(c[i]); j++) {
        ho(c[i][j]);
        if (j != 0 && s[c[i][j]] == s[c[i][j-1]]) {
            merge(into, c[i][j]);
        } else into = c[i][j];
    }
    c[i].erase(std::unique(c[i].begin(), c[i].end(), eq), c[i].end());
    for (int j : c[i]) count[i] += count[j];
    //printf("hi %d %d\n", i, count[i]);
    if (domax(ans, count[i] + foo[i])) { anscount = 1; }
    else if (ans == count[i] + foo[i]) anscount++;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &foo[i]);
    scanf(" %s", s);

    for (int i = 0; i < N-1; i++) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    go(0);
    ho(0);

    printf("%d\n%d\n", ans, anscount);
}