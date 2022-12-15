#include<iostream>

using namespace std;

int main ()
{
    int n,a,b,maxi=0,p,i;

    cin>>n>>a>>b;

    if(b==0)
    {
        maxi=max(maxi,a/n);
        cout<<maxi<<endl;
        return 0;
    }
    if(a==0)
    {
        maxi=max(maxi,b/n);
        cout<<maxi<<endl;
        return 0;
    }

    for(i=1;i<n;i++)
    {
        p=(int)min(a/i,b/(n-i));

        if(a/i==0 || b/(n-i)==0)continue;

        if(p>maxi)maxi=p;
    }

    //maxi=(int)max(maxi,max(a/n,b/n));


    cout<<maxi<<endl;

    return 0;
}