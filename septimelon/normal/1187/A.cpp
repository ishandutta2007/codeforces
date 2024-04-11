#include <iostream>

using namespace std;

int main()
{
    int q;
    int n, s, t;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n >> s >> t;
        cout << max(n-s+1, n-t+1) << endl;
    }
    return 0;
}