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
        int a[300005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        int l[300005], d[300005];
        for(int i = 0; i < n; i++){
            l[i] = -1;
            d[i] = 0;
        }
        for(int i = 0; i < n; i++){
            d[a[i]] = max(d[a[i]], i - l[a[i]]);
            l[a[i]] = i;
        }
        for(int i = 0; i < n; i++){
            d[a[i]] = max(d[a[i]], n - l[a[i]]);
        }
        int b[300005];
        for(int i = 0; i <= n; i++) b[i] = -1;
        for(int i = n - 1; i >= 0; i--){
            b[d[i]] = i + 1;
        }
        int r = -1;
        for(int i = 1; i <= n; i++){
            if(r == -1) r = b[i];
            else if(b[i] != -1) r = min(r, b[i]);
            cout << r << " ";
        }
        cout << endl;
    }
}