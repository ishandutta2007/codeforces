#include <iostream>

using namespace std;

int main()
{
    int n, p[100000], l[100000];
    cin >> n;
    for (int i=0; i<n; i++)
    {cin >> p[i]; p[i]--;}
    int k=0; int it, it0;
    for (int i=0; i<n; i++)
    {
        if (p[i]!=-1)
        {
            l[k]=1;
            it=p[i];
            while (it!=i)
            {
                it0=it;
                l[k]++;
                it=p[it];
                p[it0]=-1;
            }
            k++;
        }
    }
    for (int i=k-1; i>0; i--)
        if (l[i]>l[i-1])
        {
            it=l[i];
            l[i]=l[i-1];
            l[i-1]=it;
        }
    for (int i=k-1; i>0; i--)
        if (l[i]>l[i-1])
        {
            it=l[i];
            l[i]=l[i-1];
            l[i-1]=it;
        }
    long long int sum=0; long int sum1;
    if (k==1)
        {
            sum=l[0]; sum*=l[0];
            cout << sum;
        }
    else
    {
        sum=l[0]; sum+=l[1];
        sum*=sum;
        for (int i=2; i<k; i++)
        {
            sum1=l[i]; sum1*=l[i];
            sum+=sum1;
        }
        cout << sum;
    }
    return 0;
}