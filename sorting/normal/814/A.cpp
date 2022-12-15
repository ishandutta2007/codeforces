#include<iostream>

using namespace std;

int a[101],b[101],x,y;

bool boo=true;

int main ()
{
    int n,m,i,j,y=-3;

    ios::sync_with_stdio(false);

    cin>>n>>m;

    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)x=i;
        else
        {
            if(i!=0)
            {
                if(a[i]<=y)boo=false;
                y=a[i];
            }
            else y=a[i];
        }
    }
    for(j=0;j<m;j++)cin>>b[j];

    if(boo==false)
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    if(m>1)cout<<"Yes"<<endl;
    else
    {
        if(x==0)
        {
            if(a[1]>b[0])
            {
                cout<<"No"<<endl;
                return 0;
            }
            else
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        else
        {
            if(x==n-1)
            {
                //cout<<a[n-2]<<" "<<b[0]<<endl;
                if(a[n-2]<b[0])
                {
                    cout<<"No"<<endl;
                    return 0;
                }
                else
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
            else
            {
                if(a[x+1]>b[0] && b[0]>a[x-1])
                {
                    cout<<"No"<<endl;
                    return 0;
                }
                else
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}