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
const int N = 100005;
map<int , LL> hash;

void work() {
    int n , i , x , y;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d",&x);
        ++ hash[x];
    }
    x = hash.begin() -> first;
    y = (-- hash.end()) -> first;
    printf("%d " , y - x);
    if (x != y)
        cout << hash[x] * hash[y] << endl;
    else
        cout << hash[x] * (hash[x] - 1) / 2 << endl;
}

int main() {
    //freopen("~input.txt" , "r" , stdin);
    work();
    return 0;
}