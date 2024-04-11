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
const int N = 1005;
const int M = 2000005;

int main() {
    int n;
    int Mx = -1 << 30 , mx = 1 << 30;
    int My = -1 << 30 , my = 1 << 30;
    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        int x , y;
        cin >> x >> y;
        Mx = max(Mx , x);
        mx = min(mx , x);
        My = max(My , y);
        my = min(my , y);
    }
    int L = max(Mx - mx , My - my);
    cout << (LL) L * L << endl;
    return 0;
}