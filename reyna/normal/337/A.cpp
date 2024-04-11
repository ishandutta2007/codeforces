#include <iostream>
using namespace std;
int arr[100000];
int c;
int main(){
    int k;
    cin >> k;
    int n;
    cin >> n;
    int min = 1000000000;
    for(int i = 0; i< n; i++)
        cin >> arr[i];
    for(int i = 0; i< n; i++)
        for(int j = i; j>0; j--)
            if(arr[j] < arr[j-1]){
                c = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = c;
            }
    for(int i = k-1; i < n;i++){
        if(min > arr[i]-arr[i-k+1]){
            min = arr[i]-arr[i-k+1];
        }
    }
    cout << min;
    
}