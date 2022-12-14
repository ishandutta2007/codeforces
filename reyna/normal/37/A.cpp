#include <iostream>
using namespace std;
int arr[1000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr[a-1]++;
    }
    int counter = 0;
    int max = 0;
    for(int i = 0; i < 1000;i++){
        if(max < arr[i]){
            max = arr[i];
        }
        if(arr[i] > 0){
            counter++;
        }
    }
    cout << max << " " << counter;
    
}