#include <iostream>
using namespace std;
int arr[123456];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n-k;i++){
        cout << i+1 << " ";
    }
    for(int i = n-k;i < n;i++){
        arr[i+k-n] = i+1;
    }
    bool l= true;
    int cnt = 0;
    int cnt1 = 0;
    for(int i = 0; i < k;i++){
        if(l){
            cout << arr[k-cnt-1] << " ";
            cnt++;
            l = false;
        }else{
            cout << arr[cnt1] << " ";
            cnt1++;
            l = true;
        }
    }
    return 0;
}