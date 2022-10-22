#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int d[2]{0};
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            d[abs(a) % 2]++;
        }
        if(d[0] % 2 == 0)
        {
            if(d[1] % 4 == 1 || d[1] % 4 == 2)
            {
                cout << "Bob" << endl;
            }
            else
            {
                cout << "Alice" << endl;
            }
        }
        else
        {
            if(d[1] % 4 == 2)
            {
                cout << "Bob" << endl;
            }
            else
            {
                cout << "Alice" << endl;
            }
        }
    }
}