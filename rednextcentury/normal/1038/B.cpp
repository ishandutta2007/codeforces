#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
vector<int> v1,v2;
int main ()
{
    long long n;
    cin>>n;
    long long l=0;
    for (int i=1;i<n;i++)
    {
        l+=i;
        long long r=n*(n+1)/2 - l;
        if (__gcd(l,r)>1)
        {
            cout<<"Yes"<<endl;
            for (int i=n;i>=1;i--)
            {
                if (i<=l)
                {
                    l-=i;
                    v1.push_back(i);
                }
                else
                    v2.push_back(i);
            }
            cout<<v1.size();
            for (int i=0;i<v1.size();i++)
                cout<<' '<<v1[i];
            cout<<endl<<v2.size();
            for (int i=0;i<v2.size();i++)
                cout<<' '<<v2[i];
            cout<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}