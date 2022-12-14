#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int id=-1;
    int s=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        s+=x;
        if (s!=0)
            id=i;
    }
    if (s==0)
    {
        if (id==-1)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            cout<<2<<endl<<1<<" "<<id<<endl<<id+1<<" "<<n<<endl;
        }
    }
    else
        cout<<"YES"<<endl<<1<<endl<<1<<" "<<n<<endl;
}