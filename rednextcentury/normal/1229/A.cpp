#include<bits/stdc++.h>
using namespace std;
long long ret=0;
long long a[1000000],b[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
        cin>>b[i];
    vector<long long> can;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i]==a[j]){
                can.push_back(a[i]);
                break;
            }
        }
    }
    int sz = unique(can.begin(),can.end())-can.begin();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<sz;j++)
        {
            if ((a[i]|can[j])==can[j]){
                ret+=b[i];
                break;
            }
        }
    }
    cout<<ret<<endl;
}