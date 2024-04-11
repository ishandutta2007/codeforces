#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

char str[100];
void work() {
    int n;
    cin >> n;
    for (int i = 1 ;  ; ++ i) {
        sprintf(str , "%d" , n + i);
        if (strstr(str , "8")) {
            printf("%d\n" , i);
            return;
        }
    }
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}