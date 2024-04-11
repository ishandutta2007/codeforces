#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string o;
        cin >> o;
        if (o.find("++") != string::npos)
            x++;
        else
            x--;
    }

    cout << x << endl;
    return 0;
}