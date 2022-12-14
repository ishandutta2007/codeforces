#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define M 300101
const int mod = 1000003;

int n;

ll ABS(ll x) {return x < 0 ? -x : x;}

int main() {
    //freopen("A1.in", "r", stdin);
    scanf("%d", &n);
    ll answer = 0;
    ll cur = 0;
    while (n--) {
        ll x;
        scanf("%I64d", &x);
        answer += ABS(x - cur);
        cur = x;
    }
    printf("%I64d\n", answer);
    return 0;
}