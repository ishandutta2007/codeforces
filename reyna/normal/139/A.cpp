#include <iostream>
using namespace std;
int arr[7];
int main(){
    int n;
    cin >> n;
    int counter = 0;
    int lastday = 0;
    for(int i = 0; i < 7; i++){
        cin >> arr[i];
        counter+=arr[i];
        if(arr[i] != 0){
            lastday = i+1;
        }
    }
    n %= counter;
    if(n == 0){
        cout << lastday << endl;
        return 0;
    }
    for(int i = 0; i < 7; i++){
        n -= arr[i];
        if(n <= 0){
            cout << i+1;
            break;
        }
    }
    cout << endl;
    return 0;
}