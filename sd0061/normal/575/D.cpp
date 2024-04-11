#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;
void work() {
    int n = 1000;
    printf("%d\n" , n + n);
    for (int i = 1 ; i <= 1000 ; ++ i)
        printf("%d %d %d %d\n" , i , 1 , i , 2);
    for (int i = 1000 ; i > 0 ; -- i)
        printf("%d %d %d %d\n" , i , 1 , i , 2);    
}
int main() {
    work();
    return 0;
}