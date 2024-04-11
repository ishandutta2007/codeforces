#include<iostream>

using namespace std;

int a[101];

int main ()
{
    int n,i,st=1;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            if(st!=1)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        else
        {
            if(a[i]==a[i-1])
            {
                if(st==1)
                {
                    st=2;
                }
                if(st==3)
                {
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            else
            {
                st=3;
            }
        }

    }

    //if(st==1)cout<<"NO"<<endl;
    cout<<"Yes"<<endl;

    return 0;
}