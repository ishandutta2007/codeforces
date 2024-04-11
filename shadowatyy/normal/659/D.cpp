#include <iostream>
using namespace std;

int x[1007];
int y[1007];

int n, res, x1, y1, x2, y2, v1, v2;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];

    }

    for(int i = 2; i < n; i++)
    {
        x1 = x[i]-x[i-1];
        x2 = x[i+1]-x[i];
        y1 = y[i]-y[i-1];
        y2 = y[i+1]-y[i];

        if(y1>0)
        {
            v1 = 1;
        }

        if(y1<0)
        {
            v1 = 2;
        }

        if(x1>0)
        {
            v1 = 4;
        }

        if(x1<0)
        {
            v1 = 3;
        }

        if(y2>0)
        {
            v2 = 1;
        }

        if(y2<0)
        {
            v2 = 2;
        }

        if(x2>0)
        {
            v2 = 4;
        }

        if(x2<0)
        {
            v2 = 3;
        }

        if(v1==4 && v2==1)
            res++;

        if(v1==1 && v2==3)
            res++;

        if(v1==3 && v2==2)
            res++;

        if(v1==2 && v2==4)
            res++;
    }

    cout << res;
}