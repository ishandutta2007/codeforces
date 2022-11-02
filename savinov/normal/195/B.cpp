#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    if (!(m&1))
    {
        int k=m/2-1;
        int l=0;
        for (int i=0;i<n;i++)
        {
            cout << k+1 << endl;
            if (k==m-1)
            {
                k=m/2-1;
                l=!l;
            }
            else
            {
                k=m-1-k-l;
                l=!l;
            }

        }
    }
    else
    {
        int k=m/2;
        int l=1;
        for (int i=0;i<n;i++)
        {

            cout << k+1 << endl;
            if (k==m-1)
            {
                k=m/2;
            }
            else
            {
                k=m-1-k-l;
                l=!l;
            }
        }
    }
    return 0;
}