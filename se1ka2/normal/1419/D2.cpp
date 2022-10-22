#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100005];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    int b[100005];
    if(n % 2){
        for(int i = 0; i < n; i += 2) b[i] = a[i / 2];
        for(int i = 1; i < n; i += 2) b[i] = a[(n + 1) / 2 + i / 2];
    }
    else{
        for(int i = 0; i < n; i += 2) b[i] = a[n / 2 + i / 2];
        for(int i = 1; i < n; i += 2) b[i] = a[i / 2];
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++){
        if(b[i] < b[i - 1] && b[i] < b[i + 1]) ans++;
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
}