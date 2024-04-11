#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main(){
    int n, k;
    cin >> n >> k;
    int A[n];
    --k;
    int c = 0;
    for(int i = 0; i < n; ++i){
        cin >> A[i];
    }
    for(int i = 0; i < n; ++i){
        if(A[i] >= A[k] and A[i] > 0){
            ++c;
        }
    }
    cout << c;
    return 0;
}