// In the name of God
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000+20];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    if(n == 1){
        cout << -1 << endl;
        return 0;
    }
    sort(arr,arr+n);
    int d = arr[1]-arr[0];
    int tmp = 0;
    for(int i = 1; i < n;i++){
        if(arr[i] == arr[i-1])
            tmp++;
    }
    if(tmp == n-1){
        cout << 1 << endl;
        cout << arr[0] << endl;
        return 0;
    }
    if(n == 2 && (arr[1] - arr[0])%2){
        if(d == 0){
            cout << 1 << endl;
            cout << arr[0] << endl;
            return 0;
        }
        cout << 2 << endl;
        cout << arr[0]-d << " ";
        cout << arr[1]+d << endl;
        return 0;
    }else if(n == 2){
        if(d == 0){
            cout << 1 << endl;
            cout << arr[0] << endl;
            return 0;
        }
        cout << 3 << endl;
        cout << min((arr[1]+arr[0])/2,arr[0]-d) << " ";
        cout << max((arr[1]+arr[0])/2,arr[0]-d) << " ";
        cout << arr[1]+d << endl;
        return 0;
    }
    d = min(d,arr[2]-arr[1]);
    int cnt = 0;
    int f = 1;
    for(int i = 1; i < n;i++){
        if(arr[i]-arr[i-1] == 2*d){
            f = i;
            cnt++;
        }
    }
    for(int i = 1; i < n;i++){
        if(arr[i]-arr[i-1] != d && arr[i]-arr[i-1] != 2*d){
            cout << 0 << endl;
            return 0;
        }
    }
    if(cnt > 1){
        cout << 0 << endl;
        return 0;
    }
    if(cnt == 1){
        cout << 1 << endl;
        cout << (arr[f]+arr[f-1])/2 << endl;
        return 0;
    }
    cout << 2 << endl;
    cout << arr[0]-d << " ";
    cout << arr[n-1]+d << endl;
    return 0;
}