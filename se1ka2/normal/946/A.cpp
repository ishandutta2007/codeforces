#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[102];
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += abs(a[i]);
    }
    cout << ans << endl;
}