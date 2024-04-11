#include <iostream>
#include <algorithm>
using namespace std;
long long arr[100000];
int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    unsigned long long counter = 0;
    for(int i = 0; i < n;i++){
        counter += x*arr[i];
        if(x > 1){
            x--;
        }
    }
    cout << counter;
}