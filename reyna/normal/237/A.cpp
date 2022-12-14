#include <iostream>
using namespace std;
int arr[24][60];
int main(){
    int n;
    cin >> n;
    int max = 0;
    for(int i = 0; i < n;i++){
        int a,b;
        cin >> a >> b;
        arr[a][b]++;
    }
    for(int i = 0; i <24;i++){
        for(int j =0; j<60;j++){
            if(max < arr[i][j]){
                max = arr[i][j];
            }
        }
    }
    cout << max;
}