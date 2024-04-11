#include <iostream>
#include <string>

using namespace std;
string s;

int main()
{
    int N, M;
    cin >> N >> M;
    cin >> s;

    bool b = false;
    for (int i = 0; i < N - M; i++)
    {
        if (s[i] == '.' || s[i+M] == '.')
        {
            b = true;
            if (s[i] != '.')
                s[i+M] = '0' + '1' - s[i];
            else if (s[i+M] != '.')
                s[i] = '0' + '1' - s[i+M];
            else
            {
                s[i] = '0';
                s[i+M] = '1';
            }
        }
        if (s[i] + s[i+M] == '0' + '1')
            b = true;
    }

    if (b)
    {
        for (int i = 0; i < N; i++)
        {
            if (s[i] == '.')
                cout << '0';
            else
                cout << s[i];
        }
        cout << "\n";
    }
    else cout << "No\n";
}