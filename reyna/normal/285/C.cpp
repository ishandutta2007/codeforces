#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[300001];
int main(){
    int n;
    cin >> n;
    long long counter = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i = 1; i <= n;i++){
        counter+=abs(i-arr[i-1]);
    }
    cout << counter << endl;
    return 0;
}