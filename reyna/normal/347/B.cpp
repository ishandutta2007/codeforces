#include <iostream>
using namespace std;
int arr[100000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int counter = 0;
    bool k = false;
    for(int i = 0; i < n; i++){
        if(arr[i] == i){
            counter++;
        }
        else if(arr[arr[i]] == i){
            k = true;
        }
    }
    if(counter == n){
        cout << n << endl;
    }else if(k == true){
        cout << counter + 2 << endl;
    }else{
        cout << counter + 1 << endl;
    }
    return 0;
}