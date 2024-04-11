#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
typedef long long LL;
const int N = 100005;

void work() {
    int n;
    scanf("%d" , &n);
    vector<int> res;
    for (int i = 0 ; i < n ; ++ i) {
        bool flag = 0;
        for (int j = 0 ; j < n ; ++ j) {
            int x;
            scanf("%d" , &x);
            if (x == 1 || x == 3)
                flag = 1;
        }
        if (!flag)
            res.push_back(i + 1);
    }
    cout << res.size() << endl;
    for (int i = 0 ; i < res.size() ; ++ i)
        cout << res[i] << endl;
    
}
int main() {
    work();
    return 0;
}