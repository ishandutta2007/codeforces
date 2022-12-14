#include <iostream>
using namespace std;
int arr[100001];
int main(){
    int n;
    cin >> n;
    cin >> arr[0];
    for(int i = 1; i < n;i++)
        cin >> arr[i];
    for(int i = 1; i < n;i++){
        if(arr[i-1] > arr[i]){
            break;
        }
        if(i == n-1){
            cout << 0 << endl;
            return 0;
        }
    }
    if(arr[n-1] > arr[0]){
        cout << -1 << endl;
        return 0;
    }
    bool k = false;
    int first = 0;
    for(int i = 1; i < n;i++){
        if(k == true && arr[i] < arr[i-1]){
            cout << -1 << endl;
            return 0;
        }
        if(arr[i] < arr[i-1]){
            k = true;
            first = i;
        }
    }
    cout << n-first << endl;
    return 0;
}