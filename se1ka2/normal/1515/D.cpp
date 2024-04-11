#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        int b[200005];
        for(int i = 0; i < n; i++) b[i] = 0;
        for(int i = 0; i < l; i++){
            int c;
            cin >> c;
            c--;
            b[c]++;
        }
        for(int i = 0; i < r; i++){
            int c;
            cin >> c;
            c--;
            b[c]--;
        }
        if(l < r){
            swap(l, r);
            for(int i = 0; i < n; i++) b[i] = -b[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            while(b[i] >= 2 && l - r >= 2){
                b[i] -= 2;
                l--;
                r++;
                ans++;
            }
        }
        int c = 0;
        for(int i = 0; i < n; i++) c += abs(b[i]);
        ans += c / 2 + (l - r) / 2;
        cout << ans << endl;
    }
}