#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cou = 0;
    char c;
    int numb[26];
    for (int i = 0; i < 26; i++)
        numb[i] = 0;
    if (k > 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (cou == 0)
            {
                c = s[i];
                cou++;
            }
            else
            {
                if (s[i] == c)
                {
                    cou++;
                    if (cou == k)
                    {
                        numb[c-97]++;
                        cou = 0;
                    }
                }
                else
                {
                    cou = 1;
                    c = s[i];
                }
            }
        }
    }
    else for (int i = 0; i < n; i++)
        numb[s[i]-97]++;
    n = 0;
    for (int i = 0; i < 26; i++)
        if (numb[i] > n) n = numb[i];
    cout << n;
    return 0;
}