#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
//#pragma comment(linker, "/STACK:16777216")
using namespace std;
typedef long long LL;
const int N = 100005;
int n , b[N];
pair<int , int> a[N];
map<char , int> hash;
void work() {
    int i , j , k;
    hash['R'] = 1;
    hash['G'] = 2;
    hash['B'] = 3;
    hash['Y'] = 4;
    hash['W'] = 5;
    char s[10];
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%s" , s);
        a[i] = make_pair(hash[*s] - 1 , s[1] - '0' - 1);
    }
    sort(a , a + n);
    n = unique(a , a + n) - a;

    int ans = 1 << 30;
    for (i = 0 ; i < 1 << 10 ; ++ i) {
        memset(b , 0 , sizeof(b));
        if (i == 1 + (1 << 9))
            ++ i , -- i;
        for (j = 0 ; j < 10 ; ++ j) {
            if (i >> j & 1) {
                if (j < 5) {
                    for (k = 0 ; k < n ; ++ k)
                        if (a[k].first == j)
                            b[k] |= 1 << j;
                } else {
                    for (k = 0 ; k < n ; ++ k)
                        if (a[k].second == j - 5)
                            b[k] |= 1 << j;
                }
            }
        }
        sort(b , b + n);
        if (unique(b , b + n) - b == n)
            ans = min(ans , __builtin_popcount(i));
    }
    cout << ans << endl;
}

int main()
{
   // freopen("~input.txt" , "r" , stdin);
    //int _;  scanf("%d",&_); while (_ --)
        work();
    return 0;
}