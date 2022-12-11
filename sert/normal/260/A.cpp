#include <iostream>

using namespace std;

typedef long long ll;

ll a, b, n, ost;

int main()
{
    cin >> a >> b >> n;
    ost = b - (a * 10) % b;
    if (ost == b)
        ost = 0;

    if (ost >= 10){
        cout << "-1";
        return 0;
    }

    cout << a << ost;

    for(int i = 1; i < n; i++)
        cout << "0";

    return 0;
}