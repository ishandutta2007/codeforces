#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int num[N];
int n,m,h;
int main()
{ 
    cin>>n>>m>>h;
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        cin>>num[i];
        sum+=num[i];
    }
    if(sum<n)
        cout<<-1<<endl;
    else
    {
        double ans=1;
        for(int i=0;i<n-1;i++)
            ans*=(sum-num[h]-n+2+i)*1.0/(sum-n+1+i);
        ans=1-ans;
        cout<<ans<<endl;
    }
}