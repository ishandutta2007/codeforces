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
#include <cassert>
using namespace std;
typedef long long LL;

#define N 200010
int n , a[N];

void work() {
    int i , j , k , ans = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&a[i]);
    k = 0;
    while (k < n) {
        ++ ans;

        vector< pair<int , int> > tmp;
        for (i = k ; i < n && tmp.size() < 2 ; ++ i)
            if (a[i] > 0) {
                tmp.push_back(make_pair(i , a[i]));
            }
        if (tmp.size() < 2) {
            break;
        }
        j = i;
        LL K = tmp[1].second - tmp[0].second , W = tmp[1].first - tmp[0].first;
        if (K % W != 0) {
            k = tmp[1].first;
            continue;
        }
        LL D = K / W , B = tmp[1].second - (LL)(tmp[1].first - k) * D;
        // D(x - k) + B
        if (D > 0) {
            LL y = (LL)(j - 1 - k) * D + B;
            for (i = j - 1 ; i >= k ; -- i) {
                if (y <= 0) break;
                y -= D;
            }
            if (i >= k) {
                k = tmp[1].first;
                continue;
            }
        }
        if (D < 0) {
            LL y = B;
            for (i = k ; i < j ; ++ i) {
                if (y <= 0) break;
                y += D;
            }
            if (i < j) {
                k = tmp[1].first;
                continue;
            }
        }
        LL x = tmp[1].second;
        for (i = j ; i < n ; ++ i) {
            x += D;
            if (x <= 0 || a[i] != -1 && a[i] != x)
                break;
        }
        k = i;
    }
    cout << ans << endl;
}

int main(){
    //freopen("1.txt" , "r" , stdin);
        work();
    return 0;
}