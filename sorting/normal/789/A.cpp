#include<iostream>
#include<algorithm>

using namespace std;

int w[100000];

int main ()
{
    int n,k,i,br=0,p;

    cin>>n>>k;

    for(i=0;i<n;i++)
    {
        cin>>w[i];
        p=w[i]/k;
        if(w[i]%k!=0)p++;
        br+=p;
    }

    cout<<br/2+br%2<<endl;

    return 0;
}