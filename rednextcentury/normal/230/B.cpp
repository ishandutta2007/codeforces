#include<bits/stdc++.h>
using namespace std;
int prime[1000004];
vector<int> v;
map<long long,int> mp;
int main()
{
    for (int i=2;i<=1000000;i++)
    {
        if (prime[i])continue;
        v.push_back(i);
        long long x=i;
        mp[x*x]=1;
        int j=i+i;
        while(j<=1000000)
        {
            prime[j]=1;
            j+=i;
        }
    }
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        long long x;
        cin>>x;
        if  (mp[x])printf("YES\n");
        else printf("NO\n");
    }
}