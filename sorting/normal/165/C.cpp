#include<iostream>

using namespace std;

long long k,a[1000001];
string s;

int main ()
{
    long long i,l,curr=0,res=0;

    cin>>k>>s;

    l=s.size();
    a[0]=1;

    for(i=0;i<l;i++)
    {
        if(s[i]=='1')
        {
            curr++;
        }
        if(curr-k>=0)res+=a[curr-k];
        a[curr]++;
    }

    cout<<res<<endl;

    return 0;
}