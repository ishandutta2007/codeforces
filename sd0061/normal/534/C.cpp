#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 1000005;
int n , a[N];
LL s , K;

void work() {
    cin >> n >> K;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 0 ; i < n ; ++ i) {
        LL R = K - n + 1;
        LL L = K - s + a[i]; 
        LL p = max(min((LL)a[i] , R) - max(1LL , L) + 1 , 0LL);
        cout << a[i] - p << ' ';
    }
}

int main() {
    work();
    return 0;
}