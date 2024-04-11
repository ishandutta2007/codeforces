#include <iostream>
using namespace std;
long long a[250001];
int main()
    {
    long long n;
    long long i,j;
    long long currX,currind;
    long long maxX,maxind;
    long long step,total=0;
    long long copy;

    cin>>n;

    for (i=1;i<=n;i++)
    cin>>a[i];

    for (i=1;i<=n;i++)
        {
        currind=1;
        step=0;
        while( n-a[n]>currind )
            {
            for (j=n-1;j>=2;j--)
                {
                if (j-a[j]<=currind)
                    {
                    currind=j;
                    step++;
                    break;
                    }
                }
            }
        step++;
        total=total+step;
        copy=a[n];
        for (j=n;j>=2;j--)
            {
            a[j]=a[j-1];
            }
        a[1]=copy;
        }
    cout<<total<<endl;
    return 0;
    }