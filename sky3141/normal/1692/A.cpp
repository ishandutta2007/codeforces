#include<bits/stdc++.h>
using namespace std;
int a[4];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int b=0;
        for(int j=0;j<4;j++)
        {
            cin>>a[j];
            if(a[j]>a[0])
            {
                b++;
            }

        }
        cout<<b<<'\n';


    }
    return 0;
}