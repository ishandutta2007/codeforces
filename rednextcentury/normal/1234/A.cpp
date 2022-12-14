#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long sum=0;
        long long x;
        for (int i=0;i<n;i++){
            cin>>x;
            sum+=x;
        }
        cout<<(sum/n+((sum%n)>0))<<endl;
    }
}