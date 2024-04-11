#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 998244353;

void work() {
    int x , y , z;
    scanf("%d:%d\n%d" , &x , &y , &z);
    int h = x * 60 + y + z;
    h %= 24 * 60;
    printf("%02d:%02d\n" , h / 60 , h % 60);
}
 
int main() {
    work();
    return 0;
}