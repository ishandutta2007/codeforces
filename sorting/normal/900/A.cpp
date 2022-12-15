#include<iostream>

using namespace std;

int main ()
{
    int a=0,b=0,n,x,y;

    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x>>y;

        if(x>0)a++;
        else b++;
    }

    if(a<=1 || b<=1)
    {
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    return 0;
}