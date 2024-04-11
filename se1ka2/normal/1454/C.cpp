#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int c[200005]{0};
        int a[200005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i > 0 && a[i] != a[i - 1]) c[a[i]]++;
        }
        for(int i = 1; i <= n; i++){
            if(a[n - 1] != i) c[i]++;
        }
        int ans = n;
        for(int i = 0; i < n; i++) ans = min(ans, c[a[i]]);
        cout << ans << endl;
    }
}