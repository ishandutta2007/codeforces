#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        int p[203];
        for(int i = 0; i < n; i++) cin >> p[i];
        bool f = true;
        for(int i = 0; i < n; i++){
            if(((p[i] - p[(i + 1) % n]) + n) % n != 1 && ((p[i] - p[(i + 1) % n]) + n) % n != n - 1){
                cout << "NO" << endl;
                f = false;
                break;
            }
        }
        if(f) cout << "YES" << endl;
    }
}