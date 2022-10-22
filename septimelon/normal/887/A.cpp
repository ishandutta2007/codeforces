#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string str; int k=0;
    cin >> str;
    int i=0;
    while (str[i]=='0')
        i++;
    while (str[i]!='\0')
    {
        i++;
        if (str[i]=='0')
            k++;
    }
    if (k>=6)
        cout << "yes";
    else
        cout << "no";
    return 0;
}