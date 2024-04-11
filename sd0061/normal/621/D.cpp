#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100005;

long double mx = -1;
string res;
void update(long double x , string y) {
    if (x > mx) {
        mx = x;
        res = y;
    }
}

int main() {
    long double x , y , z;
    cin >> x >> y >> z;    
    update(log(x) * pow(y , z) , "x^y^z");
    update(log(x) * pow(z , y) , "x^z^y");
    update(log(x) * y * z , "(x^y)^z");
    update(log(y) * pow(x , z) , "y^x^z");
    update(log(y) * pow(z , x) , "y^z^x");
    update(log(y) * x * z , "(y^x)^z");    
    update(log(z) * pow(x , y) , "z^x^y");
    update(log(z) * pow(y , x) , "z^y^x");    
    update(log(z) * x * y , "(z^x)^y");    
    cout << res << endl;
    return 0;
}