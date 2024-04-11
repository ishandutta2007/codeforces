#include<iostream>

#define MAXI 5000001

using namespace std;

long long arr[5000001];

int main ()
{
    long long  t,b,a,i=2,j,p;

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(i<=MAXI)
    {
        if(arr[i])
        {
            i++;
            continue;
        }

        arr[i]++;

        for(j=2*i;j<=MAXI;j+=i)
        {
            p=j;
            while(p%i==0)
            {
                arr[j]++;
                p/=i;
            }
        }
        i++;
    }

    for(i=1;i<MAXI;i++)arr[i]+=arr[i-1];

    cin>>t;

    for(t;t>0;t--)
    {
        cin>>a>>b;

        //cout<<arr[a]<<" "<<arr[b]<<endl;

        cout<<arr[a]-arr[b]<<"\n";
    }

    return 0;
}