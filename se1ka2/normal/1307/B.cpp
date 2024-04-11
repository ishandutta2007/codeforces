#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, x;
        cin >> n >> x;
        int a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, greater<int>());
        bool f = false;
        for(int i = 0; i < n; i++){
            if(a[i] == x){
                cout << 1 << endl;
                f = true;
            }
        }
        if(f) continue;
        cout << max(2, (x - 1) / a[0] + 1) << endl;
    }
}