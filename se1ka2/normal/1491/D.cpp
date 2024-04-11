#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        if(u > v){
            cout << "NO" << endl;
            continue;
        }
        bool b[2][32];
        for(int i = 0; i < 30; i++){
            b[0][i] = ((u >> i) & 1);
            b[1][i] = ((v >> i) & 1);
        }
        int c = 0, d = 0;
        bool f = true;
        for(int i = 0; i < 30; i++){
            c += b[0][i];
            d += b[1][i];
            if(c < d) f = false;
        }
        if(f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}