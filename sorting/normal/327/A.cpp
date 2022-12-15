#include<iostream>

using namespace std;

bool a[101];
int one[101];

int main ()
{
    int n,i,j,res=-100;

    cin>>n;

    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            one[i]=one[i-1];
        }
        else
        {
            one[i]=one[i-1]+1;
        }
    }

    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if((j-i+1)-2*one[j]+2*one[i-1]>=res)
            {
                res=(j-i+1)-2*one[j]+2*one[i-1];
            }
        }
    }

    cout<<res+one[n]<<endl;

    return 0;
}