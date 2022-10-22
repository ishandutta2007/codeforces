#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    long long ans = 0;
    for(int i = 0; i < n; i++){
        if((s[i] - '0') % 2 == 0)ans += i + 1;
    }

    cout << ans;
}