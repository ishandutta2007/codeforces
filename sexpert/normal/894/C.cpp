#include <iostream>

using namespace std;

int main()
{
    int m, d;
    cin >> m;
    int S[m];
    bool valid = true;
    cin >> d;
    S[0] = d;
    for(int i = 1; i < m; i++)
    {
        cin >> S[i];
        if(S[i] % d != 0)
            valid = false;
    }
    if(!valid)
    {
        cout << "-1";
        return 0;
    }
    cout << 2*m << endl;
    for(int i = 0; i < m; i++)
    {
        cout << d << ' ' << S[i] << ' ';
    }
    return 0;
}