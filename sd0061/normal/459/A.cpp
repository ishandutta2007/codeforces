#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;


void work() {
    int x1 , x2 , y1 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int X1 = min(x1 , x2);
    int X2 = max(x1 , x2);
    int Y1 = min(y1 , y2);
    int Y2 = max(y1 , y2);
    if (X1 == X2) {
        int D = Y2 - Y1;
        printf("%d %d %d %d\n" , x1 + D , y1 , x2 + D , y2);
    } else if (Y1 == Y2) {
        int D = X2 - X1;
        printf("%d %d %d %d\n" , x1 , y1 + D , x2 , y2 + D);
    } else {
        if (X1 + Y2 != X2 + Y1) {
            puts("-1");
            return;
        }
        set< pair<int , int> > hash;
        hash.insert(make_pair(X1 , Y1));
        hash.insert(make_pair(X1 , Y2));
        hash.insert(make_pair(X2 , Y1));
        hash.insert(make_pair(X2 , Y2));
        hash.erase(make_pair(x1 , y1));
        hash.erase(make_pair(x2 , y2));
        printf("%d %d " , hash.begin() -> first , hash.begin() -> second);
        hash.erase(hash.begin());
        printf("%d %d " , hash.begin() -> first , hash.begin() -> second);
    }
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}