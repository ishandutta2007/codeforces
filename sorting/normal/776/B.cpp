#include<iostream>
#include<math.h>

using namespace std;

bool b[100002];

int main ()
{
    int n,i,j;

    ios :: sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    n++;

    if(n>3)cout<<"2"<<endl;
    else cout<<"1"<<endl;

    for(i=2;i<n;i++)
    {
        if(b[i]==0)
        {
            cout<<"1 ";

            for(j=2*i;j<=n;j+=i)b[j]=1;
        }
        else cout<<"2 ";
    }

    if(b[n]==0)cout<<"1"<<endl;
    else cout<<"2"<<endl;

    return 0;
}