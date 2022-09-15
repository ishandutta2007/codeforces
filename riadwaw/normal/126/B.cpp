#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=1000010;
#define sqr(n) ((n)*(n))
string s;
int z[N];
bool f[N];
int main()
{
    cin>>s;
    int n=s.size();
    z[0]=n;
        for (int i=1,l=0,r=0;i<n;i++)
        {
                if (i<=r)
                        z[i]=min(r-i+1,z[i-l]);
                while (i+z[i] < n && s[z[i]] == s[i+z[i]])
                        ++z[i];
                if (i+z[i]-1 > r)
                        l = i, r = i+z[i]-1;
        }
        for(int i=1;i<n;i++)
        for(int j=z[i];j>=1 && !f[j];j--)
            if (i+j<n)
                f[j]=true;
    int maxi=-1,ind=-1;
    for(int i=n-1;i>=0;i--)
        if (i+z[i]==n)
            if (f[z[i]] && z[i]>maxi)
            {
                maxi=z[i];
                ind=i;
            }
    if (maxi==-1)
    {
        cout<<"Just a legend";
        return 0;
    }
    for(int i=ind;i<ind+z[ind];i++)
        cout<<s[i];
    return 0;
}