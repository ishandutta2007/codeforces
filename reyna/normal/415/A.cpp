#include <iostream>
using namespace std;
int arr[101];
int main(){
    int n;
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        for(int i = a-1;i < n;i++){
            if(arr[i] == 0){
                arr[i] = a;
            }
        }
    }
    for(int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}