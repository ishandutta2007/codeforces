#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    cin >> m;
    long long ans[m];
    pair<long long, long long> A[m];
    long long B[m];
    
    for(int i = 0; i < m; i++){
        cin >> B[i];
    }
    for(int i = 0; i < m; i++){
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A, A+m);
    sort(B, B+m);
    for(int i = 0; i < m; i++){
        ans[A[i].second] = B[m-1-i];
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << " ";
    }
}