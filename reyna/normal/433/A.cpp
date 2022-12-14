#include <iostream>
using namespace std;
int arr[2];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a == 100){
            arr[0]++;
        }else{
            arr[1]++;
        }
    }
    if(arr[0] % 2 == 0 && arr[1] % 2 == 0 || arr[0] >= 2 && arr[1] % 2 == 1 && arr[0] % 2 == 0){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}