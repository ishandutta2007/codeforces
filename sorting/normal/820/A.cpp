#include<iostream>

using namespace std;

int c,v0,v1,a,l,k=10000000;

bool check(int t)
{
    int p=t;
    if(t>k)p=k;
    int res=v0*p-(t-1)*l+(p-1)*p*a/2;

    //cout<<res<<endl;
    if(a!=0)
    {
        res+=(t-p)*(v1);
    }

    //cout<<t<<" "<<res<<endl;

    if(res>=c)return 1;
    else return 0;
}

int main ()
{
    ios::sync_with_stdio(false);

    int beg,end,mid;

    cin>>c>>v0>>v1>>a>>l;

    beg=1;
    end=1000;
    if(a!=0)
    {
        k=(v1-v0)/a+1;
        //if((v1-v0)%a!=0)k++;
    }

    //cout<<k<<endl;

    while(beg!=end)
    {
        mid=(beg+end)/2;

        if(check(mid)==true)
        {
            end=mid;
        }
        else  beg=mid+1;
    }

    cout<<beg<<endl;

    return 0;
}