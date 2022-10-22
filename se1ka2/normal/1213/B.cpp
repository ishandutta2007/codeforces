#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int a[200004];
        for(int i = 0; i < n; i++) cin >> a[i];
        int les = 100000000;
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            if(a[i] > les) ans++;
            else les = a[i];
        }
        cout << ans << endl;
    }
}