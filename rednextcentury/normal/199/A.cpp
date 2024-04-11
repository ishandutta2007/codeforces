# include <iostream>
using namespace std;
long long a[1000];

int main()
{
    long long n;
    cin>>n;
    if (n==0)
        cout<<0<<" "<<0<<" "<<0<<endl;
    else if (n==1)
        cout<<0<<" "<<0<<" "<<1<<endl;
    else
    {
    for (long long i=0;i<60;i++)
    {
        if (i<2)
            a[i]=i;
        else
            a[i]=a[i-1]+a[i-2];
        if (a[i]==n)
            cout<<0<<" "<<a[i-2]<<" "<<a[i-1]<<endl;
    
    }
    
    }

    return 0;
}