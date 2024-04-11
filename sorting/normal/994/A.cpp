#include<iostream>

using namespace std;

int x[100];
bool b[100];

int main ()
{
    int n,m,i,j,p;

    cin>>n>>m;

    for(i=0;i<n;i++)
        cin>>x[i];

    for(j=0;j<m;j++)
    {
        cin>>p;
        b[p]=1;
    }

    for(i=0;i<n;i++)
        if(b[x[i]])
            cout<<x[i]<<" ";

    cout<<endl;

    return 0;
}