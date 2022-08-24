#include <iostream>
#include <string>

using namespace std;

int main()
{
    string x; cin >> x;
    
    bool bad = false;
    int count = 0;
    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] != '1' && x[i] != '4')
            bad = true;
        
        if (x[i] == '4')
        {
            count++;
            if (count > 2)
                bad = true;
        }
        else
            count = 0;
    }
    
    if (bad || x[0] == '4')
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}