#include <iostream>
#include <string>

using namespace std;

int main()
{
    int q, n[300];
    string s[300];
    cin >> q;
    int j;
    for (int i = 0; i < q; i++)
    {
        cin >> n[i] >> s[i];
    }
    for (int i = 0; i < q; i++)
    {
        if (n[i] > 2)
        {
            cout << "YES" << endl << "2" << endl;
            for (j = 0; j < (n[i]-1)/2; j++)
                cout << s[i][j];
            cout << " ";
            while (j < n[i])
            {
                cout << s[i][j];
                j++;
            }
            cout << endl;
        }
        else
        {
            if (s[i][0] >= s[i][1])
                cout << "NO" << endl;
            else
                cout << "YES" << endl << "2" << endl << s[i][0] << " " << s[i][1] << endl;
        }
    }
    return 0;
}