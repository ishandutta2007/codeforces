#include <iostream>

using namespace std;

int main()
{
    int n, no=0;
    long long x, y, su=0;
    bool a[300000], go=1;
    char buf;
    cin >> n >> x >> y;
    for (int i=0; i<n; i++)
    {
        cin >> buf;
        if (buf == '1') a[i] = true;
        else a[i] = false;
        if (a[i]!=go)
            if (go==0)
                go = 1;
            else {go = 0; no++;}
    }
    if (no!=0)
        if (x > y)
            su = y*no;
        else
            su = y + x*(no-1);
    cout << su;
    return 0;
}