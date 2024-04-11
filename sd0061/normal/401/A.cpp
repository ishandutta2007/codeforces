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

void work() {
    int n , D , x , ans = 0;
    cin >> n >> D;
    while (n --) {
        cin >> x , ans += x;
    }
    cout << (abs(ans) + D - 1) / D << endl;
}

int main(){
    //freopen("1.txt" , "r" , stdin);
        work();
    return 0;
}