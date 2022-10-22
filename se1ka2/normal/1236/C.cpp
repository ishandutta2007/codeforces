#include <iostream>
using namespace std;

int a[302][302];

int main()
{
    int n;
    cin >> n;
    int now = n * n;
    for(int i = 0; i < n; i++){
        if(i % 2){
            for(int j = 0; j < n; j++){
                a[j][i] = now;
                now--;
            }
        }
        else{
            for(int j = n - 1; j >= 0; j--){
                a[j][i] = now;
                now--;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            cout << a[i][j] << " ";
        }
        cout << a[i][n - 1] << endl;
    }
}