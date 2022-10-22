#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int b[100005];
        for(int i = 0; i < m; i++) b[i] = 0;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            b[a % m]++;
        }
        int ans = 0;
        for(int i = 0; i <= m / 2; i++){
            if(b[i] == 0 && b[(m - i) % m] == 0) continue;
            ans += 1 + max(0, abs(b[i] - b[(m - i) % m]) - 1);
        }
        cout << ans << endl;
    }
}