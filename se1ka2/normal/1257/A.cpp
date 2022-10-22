#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        cout << min(n - 1, abs(b - a) + x) << endl;
    }
}