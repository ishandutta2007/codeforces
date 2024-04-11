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
#include <set>
#include <map>
typedef long long LL;
using namespace std;
const int N = 500006;

int main() {
    vector<int> res;
    int n; cin >> n;
    for (int i = 1 ; i < N ; ++ i) {
        int x = 0 , y = 5 , z = i;
        while (z >= y) {
            x += z / y;
            y *= 5;                
        }
        if (x == n)
            res.push_back(i);
    }
    printf("%d\n" , (int)res.size());
    for (int i = 0 ; i < (int)res.size() ; ++ i)
        printf("%d%c" , res[i] , " \n"[i + 1 == res.size()]);
    return 0;
}