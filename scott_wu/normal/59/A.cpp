#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int lcount = 0, rcount = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            lcount++;
        else
            rcount++;
    }
    
    if (lcount >= rcount)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += 'a' - 'A';
            cout << str[i];
        }
    }
    else
    {
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] += 'A' - 'a';
            cout << str[i];
        }
    }
    cout << "\n";
    return 0;
}