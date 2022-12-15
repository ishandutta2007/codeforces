#include<iostream>

using namespace std;

int n,a[1001];

bool res1(int pos,double k,int x,int y)
{
    //cout<<1<<" "<<pos<<" "<<k<<" "<<x<<" "<<y<<endl;
    if(pos==n)return 1;
    if((double)a[pos]-a[x]==(double)k*(pos-x))
    {
        return res1(pos+1,k,x,y);
    }
    if((double)a[pos]-a[y]==(double)k*(pos-y))
    {
        return res1(pos+1,k,x,y);
    }
    return 0;
}

bool res2(int pos,double k,int x)
{
    if(pos==n)return 0;
    if((double)a[pos]-a[x]==(double)k*(pos-x))
    {
        return res2(pos+1,k,x);
    }
    return res1(pos+1,k,x,pos);
}

int main ()
{
    int i;

    cin>>n;

    for(i=0;i<n;i++)cin>>a[i];

    if(res2(2,a[1]-a[0],0))
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    if((double)(a[2]-a[0])/2+a[0]!=a[1] && res1(3,(double)(a[2]-a[0])/2,0,1))
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    if((a[2]-a[1])+a[0]!=a[1] && res1(3,(double)a[2]-a[1],0,1))
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    cout<<"No"<<endl;

    return 0;
}