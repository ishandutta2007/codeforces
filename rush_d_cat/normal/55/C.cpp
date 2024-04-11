#include <iostream>
using namespace std;
int n, m, k, x, y;
int main()
{
    cin >> n >> m >> k;
    int ok = 0;
    for(int i=1;i<=k;i++)
    {
        cin >> x >> y;
        if(x<=5 || y<=5 || (n+1-x)<=5 || (m+1-y)<=5) ok = 1;
    }
    printf("%s\n", ok?"YES":"NO");
}