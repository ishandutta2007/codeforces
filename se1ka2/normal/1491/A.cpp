#include <iostream>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int a[100005];
    int m = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m += a[i];
    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            x--;
            if(a[x] == 1){
                a[x] = 0;
                m--;
            }
            else{
                a[x] = 1;
                m++;
            }
        }
        else{
            int k;
            cin >> k;
            if(k <= m) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}