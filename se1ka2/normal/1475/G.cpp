#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int d[200005]{0};
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j * j <= a[i]; j++){
                if(a[i] % j == 0){
                    d[a[i]] = max(d[a[i]], max(d[j], d[a[i] / j]) + 1);
                }
            }
            ans = max(ans, d[a[i]]);
        }
        cout << n - ans << endl;
    }
}