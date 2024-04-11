#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005;

char str[N];

void work() {
    scanf("%s" , str);
    bool big = 0;
    for (int i = 0 ; str[i] ; ++ i) {
        if (str[i] >= '5') {
            if (!big && str[i] == '9'); else
            str[i] = 9 - str[i] + '0' + '0';
        }
        big |= (str[i] > '0');
    }
    puts(str);
}

int main() {
//    freopen("1" , "r" , stdin);

    work();
    return 0;
}