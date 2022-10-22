#include <iostream>

using namespace std;

int main(){
    int d, n, m;
    cin >> n >> d >> m;

    for(int i = 0; i < m; i++){
        long double x, y;
        cin >> x >> y;
        //cout << (y >= x - d) << ' ' << (y < x + d) << ' ' << (y > - x + d) << ' ' << (y < - x + 2 * n - d) << endl;
        if((y >= x - d) && (y <= x + d) && (y >= - x + d) && (y <= - x + 2 * n - d))cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}