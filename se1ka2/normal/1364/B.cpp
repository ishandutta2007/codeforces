#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[100005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] == a[i - 1]){
                n--;
                i--;
            }
        }
        bool b[100005];
        for(int i = 0; i < n; i++) b[i] = true;
        int ans = n;
        for(int i = 1; i < n - 1; i++){
            if((a[i] - a[i - 1]) * (a[i + 1] - a[i]) >= 0){
                b[i] = false;
                ans--;
            }
        }
        cout << ans << endl;
        for(int i = 0; i < n; i++){
            if(b[i]) cout << a[i] << " ";
        }
        cout << endl;
    }
}