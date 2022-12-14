#include <iostream>
using namespace std;
int arr[100000];
int main(){
    int n;
    cin >> n;
    int maxid = 0,max = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
            maxid = i;
        }
    }
    max = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] > max && i != maxid){
            max = arr[i];
        }
    }
    cout << maxid+1 << " " << max;
}