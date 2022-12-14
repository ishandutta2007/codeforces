#include <iostream>
using namespace std;
int arr[3456];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++)
        cin >> arr[i];
    cout << n << endl;
    for(int i = n-1; i >= 0;i--){
        int max = -1000000000-7;
        int in = 0;
        for(int j = 0; j <= i;j++){
            if(max < arr[j]){
                in = j;
                max = arr[j];
            }
        }
        swap(arr[in],arr[i]);
        cout << in << " " << i << endl;
    }
    return 0;
}