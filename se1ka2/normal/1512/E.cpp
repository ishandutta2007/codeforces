#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        l--;
        int d = r - l;
        int x[502], y[502];
        for(int i = 0; i <= d; i++){
            x[i] = i;
            y[i] = n - (d - i);
        }
        int t = 0;
        for(int i = 0; i < d; i++) t += x[i];
        int ans[502]{0};
        int i;
        for(i = d - 1; i >= 0; i--){
            if(s - t > x[i] && s - t <= y[i + 1]){
                for(int j = 0; j < i; j++) ans[l + j] = x[j + 1];
                ans[l + i] = s - t;
                for(int j = i + 1; j < d; j++) ans[l + j] = y[j + 1];
                break;
            }
            t = t - x[i] + y[i + 1];
        }
        if(i == -1){
            cout << -1 << endl;
            continue;
        }
        bool b[502]{0};
        for(int i = l; i < r; i++) b[ans[i]] = true;
        int j = 1;
        for(int i = 0; i < n; i++){
            if(i >= l && i < r) continue;
            while(b[j]) j++;
            ans[i] = j++;
        }
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}