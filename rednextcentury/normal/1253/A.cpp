#include <iostream>
#include<bits/stdc++.h>


using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int n,t,a[100500],b[100500],i,j,k,l;
    cin>>t;
    for(j=0; j<t; j++)
    {
        bool p=true,p1=true;
        cin>>n;
        for(i=0; i<n; i++)
            cin>>a[i];
        for(i=0; i<n; i++)
            cin>>b[i];
        for(i=0; i<n; i++)
        {
            if(a[i]!=b[i])
            {
                p=false;
                break;

            }
        }
        if(p==true)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else
        {
            for(i=0; i<n; i++)
            {
                if(a[i]!=b[i])
                {
                    k=b[i]-a[i];
                    l=i;
                    break;
                }
            }
        }
        if(k<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            for(i=l; i<n; i++)
            {
                if(a[i]==b[i])
                    break;
                else
                    a[i]+=k;
            }
        }
        for(i=0; i<n; i++)
        {
            if(a[i]!=b[i])
            {
                p1=false ;
                break;
            }
        }
        if(p1==true)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;
}