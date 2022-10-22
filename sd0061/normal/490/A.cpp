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
#include <bitset>
#include <cassert>
using namespace std;
typedef long long LL;
const int N = 100005;

vector<int> a[4];

void work() {
    int n , i , x;
    cin >> n ;
    for (i = 0 ; i < n ; ++ i) {
        cin >> x;
        a[x].push_back(i + 1);
    }
    n = min(a[2].size() , min(a[1].size() , a[3].size()));
    cout << n << endl;
    for (i = 0 ; i < n ; ++ i) {
        cout << a[1][i] << ' ';
        cout << a[2][i] << ' ';
        cout << a[3][i] << endl;
    }
}

int main() {
    //freopen("~input.txt" , "r" , stdin);

    work();
    return 0;
}