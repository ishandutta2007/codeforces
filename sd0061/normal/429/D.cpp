#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
typedef long long LL;
#define N 100005
int n , a[N] , s[N];

inline LL G(int i , int j) {
    return (LL)(j - i) * (j - i) + (LL)(s[j] - s[i]) * (s[j] - s[i]);
}

void work()
{
    int i , j;
    scanf("%d",&n);
    for (i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    LL ans = 1LL << 62;
    for (i = 1 ; i <= n ; ++ i) {
        for (j = 1 ; i + j <= n && j <= 80 ; ++ j) {
            ans = min(ans , G(i , i + j));
        }
    }
    set< pair<int , int> > hash;
    set< pair<int , int> >::iterator itl , itr;
    for (i = 1 ; i <= n ; ++ i) {
        itl = itr = hash.lower_bound(make_pair(s[i] , -1 << 30));
        j = 0;
        if (itl != hash.end())
            while (j < 20) {
                ++ j;
                ans = min(ans , G(itl -> second , i));
                if (itl == hash.begin()) break;
                -- itl;
            }
        j = 0;
        while (itr != hash.end() && j < 20) {
            ++ j;
            ans = min(ans , G(itr -> second , i));
            ++ itr;
        }
        hash.insert(make_pair(s[i] , i));
    }


    cout << ans << endl;
}

int main()
{
    work();
    return 0;
}