#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, num[105];
    ll sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        if(num[i] >= 0) sum += num[i];
        else sum -= num[i];
    }
    cout << sum;


}