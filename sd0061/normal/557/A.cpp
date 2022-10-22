#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long LL;
const int N = 100005;

void work() {
    int n , l[3] , r[3];
    cin >> n;
    for (int i = 0 ; i < 3 ; ++ i)
        cin >> l[i] >> r[i];
    for (int i = r[0] ; i >= l[0] ; -- i) {
        int m = n - i;
        if (l[1] + l[2] <= m && m <= r[1] + r[2]) {
            int L = max(l[1] , m - r[2]);
            int R = min(r[1] , m - l[2]);
            if (L <= R) {
                printf("%d %d %d\n" , i , R , m - R);
                return;
            }
        }        
    }

}

int main() {
    work();
    return 0;
}