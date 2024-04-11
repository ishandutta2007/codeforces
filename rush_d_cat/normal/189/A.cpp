#include <iostream>
using namespace std;
int n, a, b, c;
int main()
{
    cin >> n >> a >> b >> c;
    int res = 0;
    for(int i=0;i<=n/a;i++)
    {
        for(int j=0;j<=n/b;j++)
        {
            if(a*i+b*j > n) continue;
            if((n-a*i-b*j)% c == 0)
            {
                res = max(res, i+j+(n-a*i-b*j)/c);
            }
        }
    }
    cout << res << endl;
}