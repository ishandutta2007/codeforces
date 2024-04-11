#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cctype>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 200005;

int n , K , a[N];

int sg0(int x) {   
    if (x <= 3) {
        if (~K & 1) {
            if (x == 3)
                return 0;
            return x;
        } else
            return x & 1;
    }
    if (~K & 1)
        return ~x & 1;
    else {
        if (x & 1)
            return 0;
        int y = x , z = 0;
        while (y % 2 == 0) {
            y /= 2;
            ++ z;
        }
        if (y == 1)
            return 1 + (z % 2 == 0);
        if (y == 3)
            return 1 + (z % 2 == 1);
        return 1 + (z % 2 == 0);
    }
}
int main() {
    int res = 0;
    scanf("%d%d" , &n , &K);
    for (int i = 0 , x ; i < n ; ++ i) {
        scanf("%d" , &x);
        res ^= sg0(x);
    }
    puts(res ? "Kevin" : "Nicky");
    return 0;

}