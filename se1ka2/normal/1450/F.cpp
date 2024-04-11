#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100005];
        int b[100005];
        int c[100005];
        for(int i = 0; i < n; i++) b[i] = c[i] = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            c[a[i]]++;
        }
        int l = 0;
        for(int i = 0; i < n; i++) l = max(l, c[i]);
        if(l > (n + 1) / 2){
            cout << -1 << endl;
            continue;
        }
        b[a[0]]++;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i - 1]) b[a[i]] += 2;
        }
        b[a[n - 1]]++;
        l = 0;
        for(int i = 0; i < n; i++) l = max(l, b[i]);
        int s = 0;
        for(int i = 0; i < n; i++) s += b[i];
        cout << max(l - 2, s / 2 - 1) << endl;
    }
}