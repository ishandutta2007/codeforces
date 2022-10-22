#include <iostream>
using namespace std;

int c[1002][1002];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if(a >= 2 && b >= 2){
        cout << "NO" << endl;
        return 0;
    }
    if(n == 2 || n == 3){
        if(a == 1 && b == 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    if(a == 1 && b == 1){
        for(int i = 0; i < n - 1; i++) c[i][i + 1] = c[i + 1][i] = 1;
    }
    else if(b == 1){
        for(int i = a; i < n; i++){
            c[a - 1][i] = c[i][a - 1] = 1;
        }
    }
    else{
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(i != j) c[i][j] = 1;
        for(int i = b; i < n; i++){
            c[b - 1][i] = c[i][b - 1] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) printf("%d", c[i][j]);
        cout << endl;
    }
}