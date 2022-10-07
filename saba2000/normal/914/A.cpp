#include<bits/stdc++.h>
using namespace std;
int a[100009];
main()
{
    int n;
    cin >> n;
    int m=-100000000;
    for (int i = 0; i <n; i++)
    {
        cin >> a[i];
        if (a[i] < 0) m = max(m,a[i]);
        else
        {
            if(sqrt(a[i])!=(int)sqrt(a[i])) m=max(m,a[i]);
        }

    }
    cout <<m<<endl;
}