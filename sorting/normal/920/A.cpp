#include<iostream>

using namespace std;

int a[100010];

int main ()
{
    int t,n,k,mini,i,j;

    cin>>t;

    for(t;t>0;t--)
    {
        cin>>n>>k;

        for(i=0;i<k;i++)
            cin>>a[i];

        mini=a[0]-1;

        for(j=1;j<k;j++)
        {
            mini=max(mini,(a[j]-a[j-1]-1)/2+(a[j]-a[j-1]-1)%2);
        }

        mini=max(n-a[k-1],mini);

        cout<<mini+1<<endl;
    }

    return 0;
}