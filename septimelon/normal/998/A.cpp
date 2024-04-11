#include <iostream>

using namespace std;

int main()
{
    int n, a[10];
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    if (n<2) cout << -1 << endl;
    else if (n>2)
        if (a[0] < a[1])
            cout << 1 << " " << 1;
        else cout << 1 << " " << 2;
    else if (a[0]==a[1])
        cout << -1;
    else cout << 1 << " " << 1;
    return 0;
}