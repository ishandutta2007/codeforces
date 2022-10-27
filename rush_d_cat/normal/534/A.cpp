#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    if(n<=2)
    {
        cout<<1<<endl;
        cout<<1<<endl;
    }
    if((n==3))
    {
        cout<<2<<endl;
        cout<<"1 3"<<endl;
    }
    if(n==4)
    {
        cout<<4<<endl;
        cout<<"3 1 4 2"<<endl;
    }
    if(n>=5)
    {
        cout<<n<<endl;
        for(int i=1;i<=n;i+=2) cout<<i<<" ";
        for(int i=2;i<=n;i+=2)
        {
            cout<<i;
            if(i+2<=n) cout<<" ";
        }
    }
    return 0;
}