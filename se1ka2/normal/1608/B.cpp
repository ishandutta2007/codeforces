#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        if(abs(a - b) >= 2 || a + b >= n - 1){
            cout << -1 << endl;
            continue;
        }
        int l = 0, r = n;
        bool f;
        if(a >= b) f = true;
        else f = false;
        for(int i = 0; i < n; i++){
            if(f) cout << ++l << " ";
            else cout << r-- << " ";
            if(f && a){
                f = false;
                a--;
            }
            else if(!f && b){
                f = true;
                b--;
            }
        }
        cout << endl;
    }
}