#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];

    int ans = 0;
    for(int i = 0; i < n / 2; i++){
        if(a[i] == 2){
            if(a[n - i - 1] == 0)ans += x;
            else if(a[n - i - 1] == 1)ans += y;
            else ans += min(x, y) * 2;
        }
        else if(a[n - i - 1] != 2){
            if(a[i] != a[n - i - 1]){
                cout << -1;
                return 0;
            }
        }
        else if(a[n - i - 1] == 2){
            if(a[i] == 0)ans += x;
            else if(a[i] == 1)ans += y;
            else ans += min(x, y) * 2;
        }
        //cout << i << ' ' << ans << endl;
    }

    if(n % 2 == 1)ans += a[n / 2] == 2 ? min(x, y) : 0;

    cout << ans;
}