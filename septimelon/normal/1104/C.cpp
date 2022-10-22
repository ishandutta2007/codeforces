#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    cin >> s1;
    int i1, i2;
    i1 = 0; i2 = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] == '0')
        {
            if (i1 == 0)
            {
                cout << "1 1" << endl;
                i1++;
            }

            else if (i1 == 1)
            {
                cout << "3 1" << endl;
                i1 = 0;
            }
        }
        if (s1[i] == '1')
        {
            if (i2 < 3)
            {
                cout << i2+1 << " 3" << endl;
                i2++;
            }

            else if (i2 == 3)
            {
                cout << "4 3" << endl;
                i2 = 0;
            }
        }
    }
    return 0;
}