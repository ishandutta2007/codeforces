#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

int R[2005] , C[2005];

int main() {
    int n;
    scanf("%d" , &n);
    for (int i = 0 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        R[x + y] ++;
        C[x - y + 1000] ++;
    }
    LL res = 0;
    for (int i = 0 ; i <= 2000 ; ++ i) {
        res += (LL)R[i] * (R[i] - 1);
        res += (LL)C[i] * (C[i] - 1);        
    }
    cout << res / 2 << endl;
    return 0;
}