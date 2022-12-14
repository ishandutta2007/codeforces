#include <iostream>
using namespace std;
int arr[200][2];
int main(){
    int n;
    cin >> n;
    int counter = 0;
    int a1=0,a2=0,a3=0,a4=0;
    for(int i = 0; i < n;i++){
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    for(int i = 0; i < n;i++){
        for(int j = 0; j< n;j++){
            if(i != j){ 
                if(arr[i][0] > arr[j][0] && arr[i][1] == arr[j][1]){
                    a1++;
                }else if(arr[i][0] < arr[j][0] && arr[i][1] == arr[j][1]){
                    a2++;
                }else if(arr[i][0] == arr[j][0] && arr[i][1] > arr[j][1]){
                    a3++;
                }else if(arr[i][0] == arr[j][0] && arr[i][1] < arr[j][1]){
                    a4++;
                }
            }
        }
        if(a1 > 0 && a2 > 0 && a3 > 0 && a4 > 0){
            counter++;
        }
        a1 = 0;
        a2 = 0;
        a3 = 0;
        a4 = 0;
    }
    cout << counter;
}