#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int s = 0;
    char prev = 'O';
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c != prev)
            prev = c;
        else
            s++;
    }

    cout << s << endl;
    return 0;
}