#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <cmath>
#include <cassert>
using namespace std;
typedef long long LL;

#define N 200010
int n , m;

void work() {
    cin >> n >> m;
    if (m < n - 1 || m > 2 * n + 2) {
        puts("-1");
        return;
    }
    if (m <= n) {
        for (int i = 0 ; i < m ; ++ i)
            cout << "01";
        if (m < n)
            cout << "0";
        return;
    }

    for (int i = 0 ; i <= n ; ++ i) {
        if (i < m - n - 1)
            cout << "1";
        cout << "1";
        if (i < n)
            cout << "0";
    }

}

int main(){
    //freopen("1.txt" , "r" , stdin);
        work();
    return 0;
}