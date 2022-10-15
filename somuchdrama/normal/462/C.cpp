#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> A(n);
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long ans = 0;

    for(int i = 1; i < n; ++i){
        ans += A[i - 1] * (i + 1);
    }
    ans += A[n - 1] * n;
    cout << ans;

    return 0;
}