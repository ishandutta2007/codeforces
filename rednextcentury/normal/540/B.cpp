#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,p,x,y;
    cin>>n>>k>>p>>x>>y;
    int need = n/2 + n%2;
    int sum=0;
    int num=0;
    for (int i=1;i<=k;i++){
        cin>>a[i];
        sum+=a[i];
        if (a[i]>=y)num++;
    }
    for (int i=k+1;i<=n;i++){
        if (num<need)num++,a[i]=y;
        else a[i]=1;
        sum+=a[i];
    }
    if (num>=need && sum<=x){
        for (int i=k+1;i<=n;i++)cout<<a[i]<<' ';
        cout<<endl;
    } else {
        cout<<-1<<endl;
    }
}