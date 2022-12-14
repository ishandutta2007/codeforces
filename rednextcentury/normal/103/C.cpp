#include <bits/stdc++.h>

using namespace std;
long long n,k;
char solve(long long x)
{
    if (n%2==0)
    {
        if (x%2==0)
        {
            if (k > (n-x)/2)
                return 'X';
            return '.';
        }
        else
        {
            long long rem = k - n/2;
            if (rem > (n-x)/2)
                return 'X';
            return '.';
        }
    }
    else
    {
        if (x%2==0)
        {
            if ((k-1) > (n-x)/2)
                return 'X';
            return '.';
        }
        else
        {
            if (x==n && k>0)
                return 'X';
            long long rem = k-n/2-1;
            if (rem > (n-x-1)/2)
                return 'X';
            return '.';
        }
    }
}
int main()
{
    int p;
    cin>>n>>k>>p;
    string ret="";
    while(p--)
    {
        long long x;
        cin>>x;
        ret+=solve(x);
    }
    cout<<ret<<endl;
}