#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 405;
LL a;
void work() {
    cin >> a;
    LL sum = 4500 % a;
    for (int i = 0 ; i < 99 ; ++ i) {
        LL tmp = 0;
        for (int j = 0 ; j < 10 ; ++ j)
            tmp += sum , tmp %= a;
        sum = tmp;
    }
    sum += 1 , sum %= a;
    LL p = (a - sum) % a;
    cout << 1 + p << ' ';
    char s[100];
    sprintf(s , "%I64d" , p);
    int l = strlen(s);
    cout << 1;
    for (int i = 0 ; i < 100 - l ; ++ i) {
        cout << 0;
    }
    cout << p << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}