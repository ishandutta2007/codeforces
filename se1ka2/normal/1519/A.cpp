#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int r, b, d;
        cin >> r >> b >> d;
        if(r < b) swap(r, b);
        if((r + b - 1) / b > d + 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}