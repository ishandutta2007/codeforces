#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    if (a<c || b<c)
    {
        cout<<-1<<endl;
        return 0;
    }
    int T = a+b-c;
    if (T<n && T>=0)
        cout<<n-T<<endl;
    else cout<<-1<<endl;
}