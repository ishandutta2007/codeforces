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
#include <cctype>
using namespace std;
typedef long long LL;
const int N = 131072;
void work() {
    LL a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a , a + 3);
    cout << min((a[0] + a[1] + a[2]) / 3 , a[0] + a[1]) << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}