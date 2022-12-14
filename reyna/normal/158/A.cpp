#include <iostream>
using namespace std;
int arr[100000];
int main(){
    int n;
    int counter = 0;
    int maximum;
    cin >> n >> maximum;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(arr[i] >= arr[maximum-1] && arr[i] > 0){
            counter++;
        }
    }
    cout << counter;
}