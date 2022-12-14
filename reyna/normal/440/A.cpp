#include <iostream>
using namespace std;
bool arr[100000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n-1 ; i++){
        int a;
        cin >> a;
        arr[a-1] = true;
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == false){
            cout << i+1;
            return 0;
        }
    }
}