#include<iostream>
#include<vector>

using namespace std;

#define MAXI 1500001

int gcd(int a,int b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}

int a[MAXI],b[MAXI];
bool primes[MAXI];
bool l[MAXI];
bool erast[MAXI];
vector<int> erastPrimes;

int main ()
{
    int n,g=1,j,i,p,j2;
    bool boo;

    ios::sync_with_stdio(false);

    cin>>n;

    for(i=0;i<n;i++)
        cin>>a[i];

    for(i=0;i<n;i++)
    {
        boo=false;
        p=a[i];
        if(l[a[i]])
        {
            for(j=a[i]+1;true;j++)
                if(!l[j])break;

            a[i]=j;
            p=a[i];
            //cout<<a[i]<<endl;
            for(j=2;j*j<=a[i];j++)
            {
                if(a[i]%j==0)
                {
                    while(a[i]%j==0)a[i]/=j;
                    primes[j]=1;
                    //cout<<primes[j]<<endl;
                    for(j2=j;j2<=MAXI;j2+=j)
                        l[j2]=1;
                }
            }
            if(a[i]!=1)
            {
                j=a[i];
                primes[j]=1;
                //cout<<primes[j]<<endl;
                for(j2=j;j2<=MAXI;j2+=j)
                    l[j2]=1;
            }
            b[i]=p;
            //cout<<i<<endl;
            break;
        }

        a[i]=p;
        for(j=2;j*j<=a[i];j++)
        {
            if(a[i]%j==0)
            {
                while(a[i]%j==0)a[i]/=j;
                primes[j]=1;
                for(j2=j;j2<=MAXI;j2+=j)
                    l[j2]=1;
            }
        }
        if(a[i]!=1)
        {
            j=a[i];
            primes[j]=1;
            for(j2=j;j2<=MAXI;j2+=j)
                l[j2]=1;
        }
        b[i]=p;
    }
    for(j=2;j<=MAXI;j++)
    {
        if(erast[j])continue;


        if(!l[j])erastPrimes.push_back(j);

        for(j2=j;j2<=MAXI;j2+=j)
            erast[j2]=1;
    }
    //cout<<erastPrimes.size()<<endl;
    j=0;
    for(i=i+1;i<n;i++)
    {
        b[i]=erastPrimes[j];
        j++;
    }

    for(i=0;i<n-1;i++)
        cout<<b[i]<<" ";
    cout<<b[i]<<"\n";

    return 0;
}