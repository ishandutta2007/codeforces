#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    if (n==0&&m!=0)
    {
        cout << "Impossible\n";
        return 0;

    } else if (n==0&&m==0)
    {
        cout << "0 0\n" << endl;
        return 0;
    }
    if (m<=n)
    {
        if (m>0) cout << n<< " " << n+m-1; else cout << n<< " " << n;
        return 0;
    }
    else
    {
        cout << m << " " << n-1+m;
        return 0;
    }

    return 0;
}