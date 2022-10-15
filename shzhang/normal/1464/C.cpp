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

int n; ll T;
char s[100005];

#define value(chr) (1LL << (ll)((chr) - 'a'))
int freq[30];

int main()
{
    scanf("%d%lld", &n, &T);
    scanf("%s", s + 1);
    T -= value(s[n]);
    T += value(s[n-1]);
    n -= 2;
    for (int i = 1; i <= n; i++) {
        freq[s[i] - 'a']++;
        T += value(s[i]);
    }
    if (T < 0LL || T % 2LL) {
        printf("No"); return 0;
    }
    T /= 2LL;
    for (ll i = 25; i >= 0; i--) {
        while (freq[i] && T >= (1LL << i)) {
            freq[i]--;
            T -= (1LL << i);
        }
    }
    printf("%s", T == 0 ? "Yes" : "No");
    return 0;
}