#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    cout << arr[n-1] << " ";
    for(int i = 1; i < n-1; i++)
        cout << arr[i] << " ";
    cout << arr[0];
    cout << endl;
    return 0;
}