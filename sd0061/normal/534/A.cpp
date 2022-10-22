#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;



void work() {
    int n ;
    cin >> n;
    if (n < 3)
        cout << 1 << endl << 1 << endl;
    else if (n == 3)
        cout << 2 << endl << 1 << ' ' << 3 << endl;
    else {
        cout << n << endl;
        for (int i = n ; i > 0 ; -- i)
            if (i & 1)
                cout << i << ' ';
        for (int i = n ; i > 0 ; -- i)
            if (~i & 1)
                cout << i << ' ';        
    }
}

int main() {
    work();
    return 0;
}