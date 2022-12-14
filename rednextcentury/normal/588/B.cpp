# include<iostream>
# include<algorithm>
# include<string>
# include<cstring>
# include<stdio.h>
# include<cmath>
# include<iomanip>
# include<map>
# include<cstdlib>
# include<vector>
# include<set>
# include<queue>
# include<assert.h>
using namespace std;
bool prime[1000001];
vector<long long> primes;
int is[1000001],cur[1000001];
long long mx=0;
void solve(long long a,long long b)
{
//    vector<int> div;
//    long long x=1;
//    for (;x*x<=a;x++)
//    {
//        if (a%x==0)
//        {
//            if (x*x==a)
//                div.push_back(x);
//            else
//                div.push_back(x),div.push_back(a/x);
//        }
//    }

    int num=primes.size();
    bool p1=1,p2=1;
    for (int i=0;i<num;i++)
    {
        long long x=primes[i];
        if (x>a)
            break;
        long long h=a;
        while(h%x==0)
        {
            cur[i]++;
            h/=x;
        }

    }
    for (int i=0;i<num;i++)
    {
        if (cur[i]>1)
            p1=0;
        if (is[i]-cur[i]>1)
            p2=0;
        cur[i]=0;
    }
    if (p1) mx=max(mx,a);
    if (p2) mx=max(mx,b);
}
int main()
{
    for (int i=2;i<=1000000;i++)
    {
        if (!prime[i])
        {
            primes.push_back(i);
            int j=i+i;
            while(j<=1000000)
                prime[j]=1,j+=i;
        }
    }
    long long n;
    cin>>n;
    int num=primes.size();
    for (int i=0;i<num;i++)
    {
        long long x=primes[i]*primes[i];
        if (x>n)
            break;
        long long h=n;
        while(h%x==0)
        {
            is[i]+=2;
            h/=x;
        }
        if (h%primes[i]==0)
            is[i]++;
    }
    vector<long long> divs;
    long long x=1;
    for (;x*x<n;x++)
    {
        if (n%x==0)
            divs.push_back(x),divs.push_back(n/x);
    }
    if (x*x==n)
        divs.push_back(x);
    //solve(1000000,1000000);
    int m=divs.size();
    for (int i=0;i<m;i++)
    {
        if (divs[i]*divs[i]>n)
            continue;
        long long p1=divs[i],p2=n/divs[i];
        solve(p1,p2);
    }

    cout<<mx<<endl;
}