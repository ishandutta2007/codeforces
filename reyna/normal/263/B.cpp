#include <iostream>
using namespace std;
int c;
int arr[100000];
int main(){
    int n;
    int k;
    cin >> n >> k;
    if(k > n){
        cout << -1;
        return 0;
    }
    for(int i = 0; i< n; i++)
        cin >> arr[i];
    for(int i = 0; i< n; i++)
        for(int j = i; j>0; j--)
            if(arr[j] < arr[j-1]){
                c = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = c;
            }
    cout << arr[n-k] << " " << 0;
}