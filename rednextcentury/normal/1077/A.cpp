#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,k;
        cin>>a>>b>>k;
        long long pos = (k/2)*a-(k/2)*b;
        if (k%2)pos+=a;
        cout<<pos<<endl;
    }
}