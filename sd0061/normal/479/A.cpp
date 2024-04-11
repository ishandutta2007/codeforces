#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 1005;
const int M = 2000005;

int main() {
    int a , b , c;
    cin >> a >> b >> c;
    cout << max(a * b * c , max(a * (b + c) , max((a + b) * c , a + b + c))) << endl;
    return 0;
}