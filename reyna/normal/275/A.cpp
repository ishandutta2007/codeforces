#include <iostream>
#include <cmath>
using namespace std;
int arr[3][3];
int main(){
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = 1;
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int c;
            cin >> c;
            for(int a = 0; a < 3;a++){
                for(int b = 0; b < 3;b++){
                    if((abs(i-a) + abs(j-b))<=1){
                        if(c % 2 == 1){
                            arr[a][b] = 1-arr[a][b];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i<3;i++){
        for(int j = 0; j<3;j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}