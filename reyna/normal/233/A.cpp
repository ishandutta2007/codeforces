#include <iostream>
using namespace std;
int arr[100];
int main(){
    int n;
    cin >> n;
    if(n % 2 == 1){
        cout << -1;
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(i!=0){
            cout << " ";
        }
        if(i%2 == 0){
            cout << i+2;
        }else{
            cout << i ;
        }
        
    }
        
}