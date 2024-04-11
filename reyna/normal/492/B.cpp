// In the name of God
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int arr[1234];
int main(){
    int n,l;
    cin >> n >> l;
    for(int i = 0; i < n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    long double ans = max((long double)arr[0],(long double)l-arr[n-1]);
    for(int i = 1;i < n;i++){
        ans = max(ans,((long double)arr[i]-arr[i-1])/2);
    }
    cout << setprecision(9) << fixed << ans << endl;
    return 0;
}