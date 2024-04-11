#include <iostream>
using namespace std;
int t, a, b;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a == 0 && b == 0) cout << "0\n";
        else if (a - b == 0) cout << "1\n";
        else if ((a + b) % 2 == 0) cout << "2\n";
        else cout << "-1\n";
    }
}