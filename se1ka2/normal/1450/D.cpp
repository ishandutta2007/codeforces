#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[300005];
        int b[300005];
        for(int i = 0; i < n; i++) b[i] = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            b[a[i]]++;
        }
        bool f = true;
        for(int i = 0; i < n; i++){
            if(b[i] != 1) f = false;
        }
        bool ans[300005];
        for(int i = 0; i < n; i++) ans[i] = false;
        ans[0] = f;
        int i = 0, j = n - 1;
        for(int u = 0; u < n; u++){
            if(b[u] == 0) break;
            ans[n - 1 - u] = true;
            if(b[u] >= 2) break;
            if(a[i] == u) i++;
            else if(a[j] == u) j--;
            else break;
        }
        for(int i = 0; i < n; i++) cout << ans[i];
        cout << endl;
    }
}