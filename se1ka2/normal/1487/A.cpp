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
        int a[102];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > a[0]) ans++;
        }
        cout << ans << endl;
    }
}