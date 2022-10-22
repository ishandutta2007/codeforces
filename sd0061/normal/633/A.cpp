#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
typedef long long LL;
using namespace std;
const int N = 26;

int main() {
    int a , b , c;
    cin >> a >> b >> c;
    for (int x = 0 ; x <= c ; x += a) {
        if ((c - x) % b == 0) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}