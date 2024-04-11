#include <iostream>

using namespace std;

int main()
{
    int a,b,c,n;
    cin >> n >> a >> b >> c;
    int p[100000];
    for (int i=0;i<=(n+a+b+c);i++) p[i]=-1;
    p[0]=0;
    for (int i=0;i<=n;i++)
    {
        if (p[i]>=0)
        {
            if (p[i+a] < p[i]+1) p[i+a]=p[i]+1;
            if (p[i+b] < p[i]+1) p[i+b]=p[i]+1;
            if (p[i+c] < p[i]+1) p[i+c]=p[i]+1;
        }
    }
    cout << p[n];
    return 0;
}