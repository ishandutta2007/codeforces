#include<iostream>
#include<cmath>

using namespace std;

int main ()
{
    int n,pos,l,r,distl,distr;

    cin>>n>>pos>>l>>r;

    distl=abs(pos-l)+1;
    distr=abs(pos-r)+1;

    if(r==n)
    {
        if(l==1)
        {
            cout<<"0"<<endl;
            return 0;
        }

        cout<<distl<<endl;
        return 0;
    }

    if(l==1)
    {
        cout<<distr<<endl;
        return 0;
    }

    if(r-pos<pos-l)
    {
        cout<<distr+r-l+1<<endl;
    }
    else cout<<distl+r-l+1<<endl;

    return 0;
}