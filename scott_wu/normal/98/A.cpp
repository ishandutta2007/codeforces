#include <iostream>
#include <algorithm>

using namespace std;

int convert (char c) //{R, O, Y, G, B, V}
{
        if (c == 'R')
            return 0;
        if (c == 'O')
            return 1;
        if (c == 'Y')
            return 2;
        if (c == 'G')
            return 3;
        if (c == 'B')
            return 4;
        return 5;
}

int main()
{
    char color[6];
    for (int a = 0; a < 6; a++)
        cin >> color[a];
    int perm[6];
    for (int a = 0; a < 6; a++)
        perm[a] = convert (color[a]);
    int num[6];
    for (int a = 0; a < 6; a++)
        num[a] = 0;
    for (int a = 0; a < 6; a++)
        num[perm[a]]++;
    sort (num, num + 6);
    if (num[5] == 6)
        cout << "1\n";
    if (num[5] == 5)
        cout << "1\n";
    if (num[5] == 4)
        cout << "2\n";
    if (num[5] == 3)
    {
        if (num[4] == 3)
            cout << "2\n";
        if (num[4] == 2)
            cout << "3\n";
        if (num[4] == 1)
            cout << "5\n";
    }
    if (num[5] == 2)
    {
        if (num[4] == 1)
            cout << "15\n"; //?
        if (num[4] == 2)
        {
            if (num[3] == 2)
                cout << "6\n"; //?
            if (num[3] == 1)
                cout << "8\n"; //?
        }
    }
    if (num[5] == 1)
        cout << "30\n";
    //for (int a = 0; a < 6; a++)
    //    cout << num[a] << "\n";
    //system ("Pause");
    return 0;
}