#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
const int N = 100005;

int main() {

    LL x1 , x2 , y1 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    LL d = (y2 - y1) / 2 + 1;
    LL res = d * (x2 - x1 + 1);    
    res -= (x2 - x1) / 2;    
    cout << res << endl;
    return 0;
}