#include <iostream>
#include <string>
using namespace std;
int arr[301];
int main(){
    int n;
    cin >> n;
    char LeftOrRight = 'R';
    char RightOrLeft = 'L';
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < n;i++){
        if(i == 1){
            LeftOrRight = 'L';
            RightOrLeft = 'R';
        }
        for(int j = 0; j < arr[i];j++){
            if(j == 0){
                cout << 'P';
            }
            else{
                cout << LeftOrRight << RightOrLeft << 'P';
            }
        }
        if(i != n-1){
            cout << 'R';
        }
    }
}