#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;
const int Q = 1e9 + 7;

int main() {
    set<int> Hash;
    int n , m;
    scanf("%d%d" , &n , &m);
    for (int i = 0 ; i < n ; ++ i) {
        int x , y;
        scanf("%d" , &x);
        while (x --) {
            scanf("%d" , &y);
            Hash.insert(y);
        }
    }
    puts(Hash.size() == m ? "YES" : "NO");
    return 0;
}