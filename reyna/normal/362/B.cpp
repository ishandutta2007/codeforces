#include <iostream>
#include <algorithm>
using namespace std;
int arr[3001];
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    bool k = false;
    for(int i = 0; i < m;i++){
        cin >> arr[i];
        if(arr[i] == 1 || arr[i] == n){
            cout << "NO" << endl;
            k = true;
            break;
        }
    }
    if(k == true){
        return 0;
    }
    sort(arr,arr+m);
    int counter = 0;
    for(int i = 0; i < m;i++){
        if(arr[i] == arr[i-1]+1){
            counter++;
        }else{
            counter = 0;
        }
        if(counter == 2){
            cout << "NO" << endl;
            k = true;
            break;
        }
    }
    if(k == true){
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}