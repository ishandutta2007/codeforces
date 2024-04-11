#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    long long red = 0, blue = 0;
    for(int i = 0; i < n; ++i){
        red += a[i] >> 1;
        blue += a[i] >> 1;
        if(i & 1)
            red += a[i] & 1;
        else
            blue += a[i] & 1;
    }

    cout << min(red, blue) << "\n";
}