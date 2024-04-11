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

int n;

//int hidden[805];

int ans[805];
int pos[805];
int mod3[805], mod5[805], mod7[805], mod8[805];
bool tmp[805];

bool query(vector<int>& vec)
{
    printf("? %d ", (int)vec.size());
    for (int i = 0; i < vec.size(); i++) printf("%d ", vec[i]);
    printf("\n");
    fflush(stdout);
    int a; scanf("%d", &a);
    return (bool)a;
    /*int s = 0;
    for (int i = 0; i < vec.size(); i++) {
        s += hidden[vec[i]];
    }
    return (s % (int)vec.size()) == 0;*/
}

void final_answer()
{
    if (ans[1] > (n / 2)) {
        for (int i = 1; i <= n; i++) {
            ans[i] = n + 1 - ans[i];
        }
    }
    printf("! ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    fflush(stdout);
    exit(0);
}

void workmod(int mod, int* seq)
{
    for (int i = 1; i <= n; i++) tmp[i] = false;
    for (int i = 0; i < mod - 1; i++) {
        vector<int> base;
        for (int mask1 = 0; mask1 < 32; mask1++) {
            for (int mask2 = 0; mask2 < 32; mask2++) {
                int sumval = 0;
                vector<int> vec;
                for (int j = 0; j < 5; j++) {
                    if (mask1 & (1 << j)) {
                        sumval += j + 1;
                        vec.push_back(pos[j+1]);
                    }
                    if (mask2 & (1 << j)) {
                        sumval += n - j;
                        vec.push_back(pos[n-j]);
                    }
                }
                if (vec.size() == mod - 1 && ((sumval % mod) == ((mod - i) % mod))) {
                    base = vec; break;
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            if (ans[j] || tmp[j]) continue;
            vector<int> vec2 = base;
            vec2.push_back(j);
            if (query(vec2)) {
                tmp[j] = true; seq[j] = i;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!tmp[i] && !ans[i]) seq[i] = mod - 1;
    }
}

int main()
{
    scanf("%d", &n);
    //for (int i = 1; i <= n; i++) scanf("%d", hidden + i);
    int l = 1, r = n;
    while (l <= 5 && l < r) {
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (ans[i]) continue;
            vector<int> vec;
            for (int j = 1; j <= n; j++) {
                if (!ans[j] && j != i) vec.push_back(j);
            }
            if (query(vec)) res.push_back(i);
        }
        if (l == 1) {
            ans[res[0]] = 1;
            pos[1] = res[0];
            ans[res[1]] = n;
            pos[n] = res[1];
        } else {
            vector<int> vec;
            vec.push_back(pos[1]);
            vec.push_back(res[0]);
            int oddval = (l % 2 ? l : r);
            int evenval = (l % 2 ? r : l);
            if (query(vec)) {
                ans[res[0]] = oddval;
                pos[oddval] = res[0];
                ans[res[1]] = evenval;
                pos[evenval] = res[1];
            } else {
                ans[res[0]] = evenval;
                pos[evenval] = res[0];
                ans[res[1]] = oddval;
                pos[oddval] = res[1];
            }
        }
        l++; r--;
    }
    if (n <= 10) final_answer();
    workmod(3, mod3);
    workmod(5, mod5);
    workmod(7, mod7);
    workmod(8, mod8);
    for (int i = 1; i <= n; i++) {
        if (ans[i]) continue;
        for (int j = 1; j <= n; j++) {
            if (j % 3 == mod3[i] && j % 5 == mod5[i] &&
                j % 7 == mod7[i] && j % 8 == mod8[i]) ans[i] = j;
        }
    }
    final_answer();
    return 0;
}