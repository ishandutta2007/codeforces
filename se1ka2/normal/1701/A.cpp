#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int c = 0;
        for(int i = 0; i < 4; i++)
        {
            int a;
            cin >> a;
            c += a;
        }
        if(c == 0)
        {
            cout << 0 << endl;
        }
        else if(c == 4)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
}