#include<iostream>
#include<iomanip>

using namespace std;

long double pow(long double base,int exp)
{
    if(exp==0)
        return (long double)1.0;

    long double res=1,p;
    if(exp%2==1)
        res*=base;
    p=pow(base,exp/2);
    p*=p;
    res*=p;
    return res;
}

int a[1000001];

int main ()
{
    int n,cnt=0,i;
    long double d,d1,d2;

    cin>>n;

    if(n==5)
    {
        cout<<"Petr"<<endl;
        return 0;
    }


    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==i)
            cnt++;
    }

    if(cnt>=3)
    {
        cout<<"Petr"<<endl;
        return 0;
    }

    cout<<"Um_nik"<<endl;

    return 0;
}