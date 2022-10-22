#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n;
        cin >> n;
        int a[300005];
        for(int i = 0; i < n; i++) cin >> a[i];
        int i = 0;
        for(; i < n; i++){
            if(a[i] < i) break;
        }
        if(i == n){
            cout << "Yes" << endl;
            continue;
        }
        for(; i < n; i++){
            a[i] = min(a[i], a[i - 1] - 1);
        }
        if(a[n - 1] < 0) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}