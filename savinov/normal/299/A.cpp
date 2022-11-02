#include <algorithm>
#include <complex>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
using namespace std;


template<typename T>
T gcd(T a, T b) {
#pragma python(gcd)
    while b != 0:
        a, b = b, a % b
    return a
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int d = a[0];
    for (int i = 1; i < n; ++i)
        d = gcd(d, a[i]);
    for (int i = 0; i < n; ++i) {
        if (d % a[i] == 0) {
            cout << a[i] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}