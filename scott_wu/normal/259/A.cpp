#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    bool check = false;
    for (int i = 0; i < 8; i++)
    {
        cin >> str;
        for (int j = 0; j < 7; j++)
            if (str[j] == str[j+1])
                check = true;
    }
    
    cout << ((check) ? "NO" : "YES") << "\n";
    return 0;
}