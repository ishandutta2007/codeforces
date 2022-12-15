#include<iostream>
#include<cmath>

using namespace std;

int main ()
{
    long long i,j;

    cin>>i>>j;

    if(i==j)
    {
        cout<<"="<<endl;
        return 0;
    }
    if(i<j)
    {
        if(i==1)
        {
            cout<<"<"<<endl;
            return 0;
        }
        if(i==2 && j==3)
        {
            cout<<"<"<<endl;
            return 0;
        }
        if(i==2 && j==4)
        {
            cout<<"="<<endl;
            return 0;
        }

        cout<<">"<<endl;
    }
    else
    {
        swap(i,j);
        if(i==1)
        {
            cout<<">"<<endl;
            return 0;
        }
        if(i==2 && j==3)
        {
            cout<<">"<<endl;
            return 0;
        }
        if(i==2 && j==4)
        {
            cout<<"="<<endl;
            return 0;
        }

        cout<<"<"<<endl;
    }

    return 0;
}