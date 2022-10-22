#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[10100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;
    int now = 0;
    for(int i = 0; i < n; i++){
        now = max(now, a[i]);
        if(now == i) ans++;
    }
    cout << ans << endl;
}