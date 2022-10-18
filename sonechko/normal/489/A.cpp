#include<bits/stdc++.h>

#define ll long long
const ll MOD = 1e9 + 7;
#define mod % MOD

using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll a[n], b[n];
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    vector <ll> vec;
    vector <ll> vec1;
    for (int i=0; i<n; i++)
    {
        if (a[i]!=b[i])
        {
            for (int j=i+1; j<n; j++)
            {
                if (a[j]==b[i])
                {
                    vec.push_back(i);
                    vec1.push_back(j);
                    int l=a[i];
                    a[i]=a[j];
                    a[j]=l;
                    break;
                }
            }
        }
    }
   cout<<(int)vec.size()<<endl;
   for (int i=0; i<(int)vec.size(); i++ )
   {
       cout<<vec[i]<<" "<<vec1[i]<<endl;
   }
}