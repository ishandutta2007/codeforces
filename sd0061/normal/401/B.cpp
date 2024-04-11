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
int x , n;
bool f[N];

void work() {
    int i , j , k , mx = 0 , mn = 0;
    cin >> x >> n;
    while (n --) {
        cin >> i;
        if (i == 1)
            cin >> j >> k , f[j] = f[k] = 1;
        else
            cin >> j , f[j] = 1;
    }
    for (i = 1 ; i < x ; ++ i) {
        if (!f[i]) {
            j = i;
            while (j < x && !f[j])
                ++ j;
            mx += j - i , mn += (j - i + 1) / 2;
            i = j - 1;
        }
    }
    cout << mn << ' ' << mx << endl;
}

int main(){
    //freopen("1.txt" , "r" , stdin);
        work();
    return 0;
}