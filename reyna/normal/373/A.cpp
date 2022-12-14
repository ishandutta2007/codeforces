#include <iostream>
#include <string>
using namespace std;
int arr[9];
int main(){
    int k;
    cin >> k;
    string a[4];
    for(int i = 0; i < 4;i++){
        cin >> a[i];
        for(int j = 0; j < 4; j++){ 
            if(a[i][j] != '.'){
                arr[int(a[i][j])-'1']++;
            }
        }
    }
    bool l = false;
    for(int i = 0; i < 9; i++){
        if(arr[i] > 2*k){
            cout << "NO" << endl;
            l = true;
            break;
        }
    }
    if(l == true){
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}