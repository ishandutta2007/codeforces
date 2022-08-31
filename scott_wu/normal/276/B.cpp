#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main()
{
    string str;
    cin >> str;
    
    int ccount = 0;
    for (int i = 0; i < 26; i++)
    {
        bool check = true;
        for (int j = 0; j < str.length(); j++)
            if (str[j] == (char) (i + 'a'))
                check = !check;
        if (!check)
            ccount++;
    }
    
    if (ccount <= 1 || (ccount % 2 == 1))
        cout << "First\n";
    else
        cout << "Second\n";
    return 0;
}