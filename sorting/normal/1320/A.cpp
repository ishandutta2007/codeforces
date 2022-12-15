#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> b(n);
    for(int i = 0; i < n; ++i)
        cin >> b[i];

    map<int, long long> sum;
    for(int i = 0; i < n; ++i)
        sum[i - b[i]] += b[i];

    long long mx = 0;
    for(auto [idx, answer]: sum)
        mx = max(answer, mx);

    cout << mx << "\n";
}