#include<iostream>
#include<algorithm>
#include<algorithm>

using namespace std;

int main ()
{
    ios::sync_with_stdio(false);

    int n,i,num;
    double best=181,a,d;

    cin>>n>>a;

    for(i=1;i<=n-2;i++)
    {
        d=(double)i*180/n;
        //cout<<d<<endl;
        d=(double)d-a;
        if(d<0)d=(double)-d;

        //cout<<" --- "<<d<<endl;
        if(d<best)
        {
            best=d;

            num=n-i;
        }
    }

    cout<<"1 "<<num<<" "<<num+1<<"\n";

    return 0;
}