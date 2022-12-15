#include<iostream>

using namespace std;

int main ()
{
    long long n,k,i,w,r=0,p;

    cin>>n>>k;

    cin>>w;

    for(i=1;i<n;i++)
    {
        cin>>p;

        if(p>w)
        {
            r=1;
            w=p;
        }
        else r++;

        if(r==k)break;
    }

    cout<<w<<endl;

    return 0;
}