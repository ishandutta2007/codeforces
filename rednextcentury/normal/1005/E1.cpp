#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
map<int,ll> num;
map<int,ll> mp[2];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll ret=0;
    int id;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]<m)a[i]=-1;
        else if (a[i]==m)a[i]=0, id = i;
        else a[i]=1;
    }
    num[0]=1;
    mp[0][0]=1;
    int sum=0;
    for (int i=1;i<=n;i++){
        sum+=a[i];
        if (i<id)num[sum]++,mp[i%2][sum]++;
        else if (i>=id)ret+=num[sum], ret+=mp[i%2][sum-1];
    }
    cout<<ret<<endl;
}