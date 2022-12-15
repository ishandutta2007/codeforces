#include<iostream>

using namespace std;

bool b[1002001];

int main ()
{
    int n,i,j,x,y,l=0,k;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>x>>y;

        if(x>l)
        {
            l=x;
        }
        else
        {
            k=(l-x)/y;
            l=x+(k+1)*y;
        }
    }

    cout<<l<<endl;

    return 0;
}