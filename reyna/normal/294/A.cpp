#include <iostream>
using namespace std;
int arr[1000];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    for(int i = 0; i < m;i++){
        int x,y;
        cin >> x >> y;
        x -= 1;
        if(x == 0){
            arr[1] += arr[0] - y;
            arr[x] = 0;
        }
        else if(x == n-1){
            arr[n-2] += y-1;
            arr[x] = 0;
        }else{
            arr[x+1] += arr[x] - y;
            arr[x-1] += y-1;
            arr[x] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
}