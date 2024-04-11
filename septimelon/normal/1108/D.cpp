#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s1;
    cin >> n >> s1;
    char s[5];
    s[0] = 'R';
    s[1] = 'G';
    s[2] = 'B';
    s[3] = 'R';
    int coun = 0;
    for (int i = 1; i < n-1; i++)
    {
        if (s1[i-1] == s1[i])
        {
            coun++;
            for (int j = 0; j < 3; j++)
                if (s1[i-1] == s[j])
                    s1[i] = s[j+1];
            if (s1[i] == s1[i+1])
                for (int j = 0; j < 3; j++)
                    if (s1[i+1] == s[j])
                        s1[i] = s[j+1];
        }
    }
    if (s1[n-1] == s1[n-2])
    {
        coun++;
        for (int j = 0; j < 3; j++)
            if (s1[n-2] == s[j])
                s1[n-1] = s[j+1];
    }
    cout << coun << endl;
    cout << s1;
    return 0;
}