#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

int n;
string a , b;

void work() {
    cin >> n >> a;
    b = a;
    for (int i = 0 ; i < n ; ++ i) {
        string c; int x = 10 - a[0] + '0';
        for (int j = 0 ; j < n ; ++ j)
            c += char((a[j] - '0' + x) % 10 + '0');
        b = min(b , c);
        rotate(a.begin() , a.begin() + 1 , a.end());
    }
    cout << b << endl;
}

int main() {
    work();
    return 0;
}