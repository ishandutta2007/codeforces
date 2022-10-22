#include <iostream>
using namespace std;

int cnt(int r, int i){
    return r / (1 << (i + 1)) * (1 << i) + max(0, r % (1 << (i + 1)) - (1 << i));
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int c = 0;
        for(int i = 0; i < 20; i++) c = max(c, cnt(r + 1, i) - cnt(l, i));
        cout << r - l + 1 - c << endl;
    }
}