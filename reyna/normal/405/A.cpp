#include <iostream>
using namespace std;
int arr[1000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i< n; i++)
        cin >> arr[i];
    for(int i = 0; i< n; i++)
        for(int j = i; j>0; j--)
            if(arr[j] < arr[j-1]){
                int c = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = c;
            }
    for(int i = 0; i < n; i++){
        cout << arr[i];
        if(i != n-1){
            cout << " ";
        }
    }
}