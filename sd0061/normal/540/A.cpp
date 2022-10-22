#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 1005;
int n;
char s[N] , t[N]; 
int main() {
    int res = 0;
    scanf("%d%s%s" , &n , s , t);
    for (int i = 0 ; s[i] ; ++ i) {
        int x = abs(s[i] - t[i]);
        res += min(x , 10 - x);
    }
    cout << res << endl;
    return 0;
}