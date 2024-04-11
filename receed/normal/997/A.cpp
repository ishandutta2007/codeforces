#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
  
using namespace std;

const int N = 300001;
char s[N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x, y, t = 0;
    scanf("%lld%lld%lld%s", &n, &x, &y, &s);
    for (int i = 0; i < n - 1; i++)
        if (s[i] == '1' && s[i + 1] == '0')
            t++;
    if (s[0] == '0')
        t++;
    if (t == 0)
        printf("0");
    else
        printf("%lld", (t - 1) * min(x, y) + y);
}