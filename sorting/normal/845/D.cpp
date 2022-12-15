#include<iostream>

using namespace std;

int a[301];

int main ()
{
    int n,i,t,br=0,res=0,sp,j,csp;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>t;
         //cout<<res<<" res"<<endl;
        if(t==1)
        {
            cin>>csp;
            for(j=1;j<csp;j++)
            {
                res+=a[j];
                a[j]=0;
            }
            continue;
        }
        if(t==2)
        {
            res+=br;
            br=0;
            continue;
        }
        if(t==3)
        {
            cin>>sp;
            for(j=1;j<sp;j++)
            {
                a[sp]+=a[j];
                a[j]=0;
            }
            a[sp]++;
            for(j=1;j<csp;j++)
            {
                res+=a[j];
                a[j]=0;
            }
            //cout<<a[sp]<<" sp"<<endl;
            continue;
        }
        if(t==4)
        {
            br=0;
            continue;
        }
        if(t==5)
        {
            for(j=1;j<301;j++)a[j]=0;
            continue;
        }
        if(t==6)
        {
            br++;
        }

    }

    cout<<res<<endl;

    return 0;
}