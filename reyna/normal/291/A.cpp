#include <iostream>
using namespace std;
int arr[1000];
int main(){
    int n;
    cin >> n;
    int c = 0;
    int a1=0,counter=0;
    for(int i = 0; i< n; i++)
        cin >> arr[i];
    for(int i = 0; i< n; i++)
        for(int j = i; j>0; j--)
            if(arr[j] < arr[j-1]){
                c = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = c;
            }
    for(int i = 0; i < n-1;i++){
        if(arr[i] == arr[i+1] && arr[i] != 0){
            counter++;
            a1++;
        }else if(arr[i] != arr[i+1]){
            a1 = 0;
        }
        if(a1 > 1){
            cout << -1;
            return 0;
        }
    }
    cout << counter;
}