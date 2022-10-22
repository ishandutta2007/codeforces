#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, m;
        cin >> n >> m;
        int a[1002];
        int s = 0;
        int l1 = -1, l2 = -1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(l1 == -1 || a[i] < a[l1]){
                l2 = l1;
                l1 = i;
            }
            else if(l2 == -1 || a[i] < a[l2]){
                l2 = i;
            }
            s += a[i] * 2;
        }
        if(n > m || n == 2){
            cout << -1 << endl;
            continue;
        }
        s += (m - n) * (a[l1] + a[l2]);
        cout << s << endl;
        for(int i = 0; i < n; i++) cout << i + 1 << " " << (i + 1) % n + 1 << endl;
        for(int i = n; i < m; i++) cout << l1 + 1 << " " << l2 + 1 << endl;
    }
}