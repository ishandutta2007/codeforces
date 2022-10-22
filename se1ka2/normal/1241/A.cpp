#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        int n;
        cin >> n;
        if(n == 2) cout << 2 << endl;
        else if(n % 2 == 1) cout << 1 << endl;
        else cout << 0 << endl;
    }
}