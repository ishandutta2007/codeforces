
#include <bits/stdc++.h>
using namespace std;
int x[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int y;
        cin>>x[i]>>y;
    }
    sort(x,x+n);
    if (x[1]<0 && x[n-1]>0 && x[n-2]>0 && x[0]<0)
        cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;
}