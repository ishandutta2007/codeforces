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
        int ans = n * 2 - 1;
        for(int i = 1; i < n - 1; i++){
            if((a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] > a[i - 1] && a[i] > a[i + 1])) ans++;
        }
        for(int i = 1; i < n - 2; i++){
            if((a[i + 1] < a[i - 1] && a[i - 1] <= a[i + 2] && a[i + 2] < a[i]) ||
               (a[i] < a[i + 2] && a[i + 2] <= a[i - 1] && a[i - 1] < a[i + 1]) ||
               (a[i + 1] < a[i + 2] && a[i + 2] <= a[i - 1] && a[i - 1] < a[i]) ||
               (a[i] < a[i - 1] && a[i - 1] <= a[i + 2] && a[i + 2] < a[i + 1])) ans++;
        }
        cout << ans << endl;
    }
}