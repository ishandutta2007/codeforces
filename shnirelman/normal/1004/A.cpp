#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    int ans = 2;

    for(int i = 0; i < n - 1; i++)
        if(a[i + 1] - a[i] > d * 2)ans += 2;
        else if(a[i + 1] - a[i] == d * 2)ans++;

    cout << ans;
}