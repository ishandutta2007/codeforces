#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cctype>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 1005;
int n , x , y , p , k;
int main() {
    cin >> n >> k >> p >> x >> y;
    int cnt = 0;
    for (int i = 0 ; i < k ; ++ i) {
        int a;
        cin >> a;
        x -= a;
        cnt += (a >= y);
    }    
    int m = (n + 1) / 2;
    k = n - k;
    vector<int> res;
    for (int i = 0 ; i < k ; ++ i) {
        if (cnt < m) {
            x -= y;
            ++ cnt;
            res.push_back(y);
        } else {
            x -= 1;
            res.push_back(1);
        }
    }
    if (x < 0 || cnt < m) {
        puts("-1");
    } else {
        for (int i = 0 ; i < k ; ++ i)
            printf("%d\n" , res[i]);
    }        
    return 0;
}