#include <iostream>

using namespace std;

int n , m , x = 1 , y = 1 , a[101][101];

int main(){
    cin >> n >> m;
    if(n * n < m){
        cout << -1;
        return 0;
    }
    while(m > 0){
        if(x == y)
            a[x][y] = 1 , m--;
        else if(m > 1)
            a[x][y] = a[y][x] = 1 , m -= 2;
        y++;
        if(y > n)
            y = x + 1 , x = y;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j < n ; j++)
            cout << a[i][j] << " ";
        cout << a[i][n] << "\n";
    }
    return 0;
}