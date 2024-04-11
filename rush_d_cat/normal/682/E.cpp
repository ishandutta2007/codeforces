#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int NICO = 5000 + 10;
typedef long long LL;
int n, a, b, c;
LL x[NICO], y[NICO], s;
LL getArea(int a, int b, int c)
{
    return abs((x[b]-x[a])*(y[c]-y[a])-(x[c]-x[a])*(y[b]-y[a]));
}
int main()
{
    cin >> n >> s;
    for(int i=1;i<=n;i++)
    {
        cin >> x[i] >> y[i];
    }
    a = 1, b = 2, c = 3;
    LL S = getArea(a, b, c);
    while(1)
    {
        int flag = 0;
        for(int i=1;i<=n;i++)
        {
            S = getArea(a, b, c);
            if(S < getArea(a, b, i)) c = i, flag = 1;
            else if(S < getArea(a, i, c)) b = i, flag = 1;
            else if(S < getArea(i, b, c)) a = i, flag = 1;
        }
        if(!flag)
        {
            break;
        }
    }
    cout << (x[a]+x[b]-x[c]) << " " << (y[a]+y[b]-y[c]) << endl;
    cout << (x[a]+x[c]-x[b]) << " " << (y[a]+y[c]-y[b]) << endl;
    cout << (x[b]+x[c]-x[a]) << " " << (y[b]+y[c]-y[a]) << endl;
}