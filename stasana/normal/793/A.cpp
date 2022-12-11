#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[100000];
    for(int i = 0; i < n; ++i) cin >> a[i];
    int r = a[0] % k;
    for(int i = 0; i < n; ++i){
        if(a[i]%k != r){
            cout << -1;
            return 0;
        }
    }
    int mn = a[0];
    for(int i = 1; i < n; ++i){
        if(a[i] < mn) mn = a[i];
    }
    long long int res = 0;
    for(int i = 0; i < n; ++i){
        res += (a[i] - mn) / k;
    }
    cout << res;
    return 0;
}