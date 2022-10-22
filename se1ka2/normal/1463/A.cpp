#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int r = min(min(a, b), c);
        int s = a + b + c;
        if(s % 9) cout << "NO" << endl;
        else if(r < s / 9) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}