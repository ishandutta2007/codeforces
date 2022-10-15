#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

char s[300000];

int input[20][300005];
int output[20][300005];
int tmp2[20][300005];
int tmp3[20][300005];
int tmp4[20][300005];
pair<ll, int> tmp[20][300000];

void solve(int lvl)
{
    int* num = input[lvl];
    if (lvl == 0) {
        output[0][0] = 0; return;
    }
    for (int i = 0; i < (1 << (lvl - 1)); i++) {
        tmp[lvl][i] = make_pair(
            num[2 * i] * 1000000LL + num[2 * i + 1], i);
    }
    sort(tmp[lvl], tmp[lvl] + (1 << (lvl - 1)));
    int curv = 1;
    for (int i = 0; i < (1 << (lvl - 1)); i++) {
        if (i > 0 && tmp[lvl][i].first > tmp[lvl][i-1].first)
            curv++;
        input[lvl-1][tmp[lvl][i].second] = curv;
    }
    solve(lvl - 1);
    for (int i = 0; i < (1 << (lvl - 1)); i++) {
        tmp2[lvl-1][i] = output[lvl-1][i];
    }
    for (int i = 0; i < (1 << (lvl - 1)); i++) {
        tmp[lvl][i] = make_pair(
            num[2 * i + 1] * 1000000LL + num[2 * i], i);
    }
    sort(tmp[lvl], tmp[lvl] + (1 << (lvl - 1)));
    curv = 1;
    for (int i = 0; i < (1 << (lvl - 1)); i++) {
        if (i > 0 && tmp[lvl][i].first > tmp[lvl][i-1].first)
            curv++;
        input[lvl-1][tmp[lvl][i].second] = curv;
    }
    solve(lvl - 1);
    bool switch_best = false;
    for (int i = 0; i < (1 << (lvl - 1)); i++) {
        tmp3[lvl][2*i] = num[2 * tmp2[lvl-1][i]];
        tmp3[lvl][2*i + 1] = num[2 * tmp2[lvl-1][i] + 1];
    }
    for (int i = 0; i < (1 << (lvl - 1)); i++) {
        tmp4[lvl][2*i + 1] = num[2 * output[lvl-1][i]];
        tmp4[lvl][2*i] = num[2 * output[lvl-1][i] + 1];
    }
    for (int i = 0; i < (1 << lvl); i++) {
        if (tmp3[lvl][i] != tmp4[lvl][i]) {
            if (tmp3[lvl][i] > tmp4[lvl][i]) switch_best = true;
            break;
        }
    }
    if (switch_best) {
        for (int i = 0; i < (1 << (lvl - 1)); i++) {
            output[lvl][2*i + 1] = 2 * output[lvl-1][i];
            output[lvl][2*i] = 2 * output[lvl-1][i] + 1;
        }
    } else {
        for (int i = 0; i < (1 << (lvl - 1)); i++) {
            output[lvl][2*i] = 2 * tmp2[lvl-1][i];
            output[lvl][2*i + 1] = 2 * tmp2[lvl-1][i] + 1;
        }
    }
}

char ans[300005];

int main()
{
    int n; scanf("%d", &n);
    scanf("%s", s);
    vector<int> num;
    for (int i = 0; i < (1 << n); i++) input[n][i] = s[i] - 'a' + 1;
    solve(n);
    for (int i = 0; i < (1 << n); i++) printf("%c", s[output[n][i]]);
    return 0;
}