#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1005;
bool f[N];
int main() {
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 2 ; i <= n ; ++ i) {
        if (f[i]) continue;
        int x = i;
        while (x <= n) {
            res.push_back(x);
            x *= i;
        }
        for (int j = i * i ; j <= n ; j += i)
            f[j] = 1;
    }
    printf("%d\n" , (int)res.size());
    for (int i = 0 ; i < res.size() ; ++ i)
        printf("%d " , res[i]);
    return 0;
}