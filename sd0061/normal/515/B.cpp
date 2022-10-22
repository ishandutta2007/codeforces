#include <iostream>
using namespace std;
int n , m;
bool f[100] , g[100];
int main() {
    int i , j , x , y;
    cin >> n >> m;
    cin >> j;
    while (j --)
        cin >> x , f[x] = 1;
    cin >> j;
    while (j --)
        cin >> x , g[x] = 1;
    for (i = 0 ; i < 2000000 ; ++ i) {
        x = i % n , y = i % m;
        f[x] = g[y] = f[x] || g[y];
    }
    for (i = 0 ; i < n ; ++ i)
        for (j = 0 ; j < m ; ++ j)
            if (!f[i] || !g[j]) {
                cout << "No";
                return 0;    
            }
    cout << "Yes";
}