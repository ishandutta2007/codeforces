//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 1e5 + 1e3;
int arr[Maxn];
int main(){
    int n,T;
    cin >> n >> T;
    for(int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int sp = 0;
    int sum = 0;
    while(sp != n && sum + arr[sp] <= T){
        sum += arr[sp++];
    }
    int ans = sp;
    for(int i = 1; i < n;i++){
        sum -= arr[i-1];
        while(sp != n && sum + arr[sp] <= T){
            sum += arr[sp++];
        }
        ans = max(ans,sp-i);
    }
    cout << ans << endl;
    return 0;
}