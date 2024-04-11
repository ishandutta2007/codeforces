#include <iostream>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        int x;
        cin >> x;
        if (x < 1400)
        {
            cout << "  Division 4\n";
        }
        else if (x < 1600)
        {
            cout << "Division 3  \n";
        }
        else if (x < 1900)
        {
            cout << "  Division 2  \n";
        }
        else
        {
            cout << "  Division    1  \n";
        }
    }

    return 0;
}