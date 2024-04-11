#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int x[102], y[102];
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
        bool f = false;
        for(int i = 0; i < n; i++){
            bool g = true;
            for(int j = 0; j < n; j++){
                if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) g = false;
            }
            f |= g;
        }
        if(f) cout << 1 << endl;
        else cout << -1 << endl;
    }
}