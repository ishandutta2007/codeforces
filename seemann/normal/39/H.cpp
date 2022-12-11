#include <iostream>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int w = i * j;
            string s;
            while (w > 0)
            {
                s = (char)(w % k + '0') + s;
                w /= k;
            }
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}