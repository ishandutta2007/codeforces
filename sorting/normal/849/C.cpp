#include<iostream>

using namespace std;

int main ()
{
    int k,i,j,j2,j3;
    char c='a';

    cin>>k;

    if(k==0)
    {
        cout<<"a"<<endl;
        return 0;
    }

    for(i=0;k!=0;i++)
    {
        for(j=2;j<=200;j++)
        {
            if(j*(j-1)/2>k)
            {
                j--;
                break;
            }
        }
        k-=j*(j-1)/2;
        for(j2=0;j2<j;j2++)
        {
            cout<<c;
        }
        c=(char)c+1;
    }
    cout<<endl;
    return 0;
}