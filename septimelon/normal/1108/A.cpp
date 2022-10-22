#include <iostream>

using namespace std;

int main()
{
    int q, l1, l2, r1, r2;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        if (l1 < l2)
            cout << l1 << " " << r2 << " ";
        else
            cout << r1 << " " << l2 << " ";
    }
    return 0;
}