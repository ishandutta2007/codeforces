#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        ll s = 0;
        for(int i = 1; i < n; i++) s += a[n - 1] - a[i];
        if(s >= a[0]) cout << s - a[0] << endl;
        else cout << ((n - 1) - (a[0] - s) % (n - 1)) % (n - 1) << endl;
    }
}