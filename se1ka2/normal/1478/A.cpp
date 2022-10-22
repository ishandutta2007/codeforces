#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int d[102]{0};
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            d[a]++;
        }
        int ans = 0;
        for(int i = 0; i <= 100; i++) ans = max(ans, d[i]);
        cout << ans << endl;
    }
}