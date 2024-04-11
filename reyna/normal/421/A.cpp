#include <iostream>
using namespace std;
int arr[100];
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    for(int i = 0; i < a; i++){
        int c;
        cin >> c;
        arr[c-1] = 1;
    }
    for(int i = 0; i < b; i++){
        int c;
        cin >> c;
        arr[c-1] = 2;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}