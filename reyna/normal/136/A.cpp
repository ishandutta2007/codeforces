#include <iostream>
using namespace std;
int arr[1000];
int ans[1000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        ans[arr[i]-1] = i+1;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
}