#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool b[200005];
        for (int i = 1; i <= n; i++)
        {
            b[i] = false;
        }
        cout << 2 << endl;
        for(int i = 1; i <= n; i++)
        {
            if(!b[i])
            {
                int j = i;
                while(j <= n)
                {
                    cout << j << " ";
                    b[j] = true;
                    j *= 2;
                }
            }
        }
        cout << endl;
    }
}