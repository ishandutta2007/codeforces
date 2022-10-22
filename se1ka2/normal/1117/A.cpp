#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[100005];
    int lar = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        lar = max(lar, a[i]);
    }
    int now = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == lar) now++;
        else now = 0;
        ans = max(ans, now);
    }
    cout << ans << endl;
}