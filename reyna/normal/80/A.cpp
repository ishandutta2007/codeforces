#include <iostream>
using namespace std;
bool arr[50];
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    for(int i = 2; i <= 50; i++){
        for(int j = 2; j*i <= 50;j++){
            if(arr[i] == true){
                break;
            }
            arr[i*j] = true;
        }
    }
    if(arr[n] == true){
        cout << "NO";
        return 0;
    }
    for(int i = n+1; i <= m; i++){
        if(arr[i] == false && i != m){
            cout << "NO";
            break;
        }else if(i == m && arr[m] == false){
            cout << "YES";
        }else if(arr[m] == true){
            cout << "NO";
            break;
        }
    }
        
}