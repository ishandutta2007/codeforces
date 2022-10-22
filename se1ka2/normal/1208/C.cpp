#include <iostream>
using namespace std;

int c[1002][1002];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n / 4; i++){
        for(int j = 0; j < n / 4; j++){
            for(int k = 0; k < 4; k++){
                for(int l = 0; l < 4; l++){
                    c[i * 4 + k][j * 4 + l] = i * (n * 4) + j * 16 + k * 4 + l;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}