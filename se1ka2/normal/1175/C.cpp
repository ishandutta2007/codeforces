#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, k;
        cin >> n >> k;
        int a[200002];
        for(int i = 0; i < n; i++) cin >> a[i];
        int now = a[k] - a[0];
        int ans = now;
        int x = (a[k] + a[0]) / 2;
        for(int i = k + 1; i < n; i++){
            now += (a[i] - a[i - 1]) - (a[i - k] - a[i - k - 1]);
            if(now < ans){
                ans = now;
                x = (a[i] + a[i - k]) / 2;
            }
        }
        cout << x << endl;
    }
}