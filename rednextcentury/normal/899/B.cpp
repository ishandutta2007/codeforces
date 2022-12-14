#include <bits/stdc++.h>

using namespace std;
int b[100];
int a[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>b[i];
    for (int i=0;i+n<72;i++)
    {
        bool ok=1;
        for (int j=0;j<n;j++)
        {
            if (b[j]!=a[i+j])
                ok=0;
        }
        if (ok)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}