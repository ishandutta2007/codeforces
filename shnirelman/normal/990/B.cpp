#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    for(int i = 0; i < n; i++){
        int j;
        for(j = i; j < n && a[j] == a[i]; j++);

        if(j >= n || a[j] > a[i] + k)ans += j - i;
        i = j - 1;
    }

    cout << ans;
}