//In the name of God
#include <iostream>
using namespace std;
int arr[5678];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        int now;
        cin >> now;
        arr[--now]++;
    }
    int ans = 0;
    for(int i = 0; i < n;i++){
        if(arr[i])
            ans++;
    }
    cout << n - ans << endl;
    return 0;
}