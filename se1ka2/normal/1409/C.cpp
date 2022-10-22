#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        int d = y - x;
        for(int c = d; c > 0; c--){
            if(d % c) continue;
            if(c >= n) continue;
            int a[52];
            a[n - 1] = y;
            for(int i = n - 2; i >= 0; i--){
                a[i] = a[i + 1] - d / c;
            }
            int s = 0;
            while(a[0] + s <= 0) s += d / c;
            for(int i = 0; i < n; i++) cout << a[i] + s << " ";
            cout << endl;
            break;
        }
    }
}