#include<bits/stdc++.h>
using namespace std;
int R[3],G[3],B[3];
int check()
{
    int mx=0;
    for (int i=0;i<3;i++)
    {
        mx=max(mx,R[i]+G[(i+1)%3]+B[(i+2)%3]);
    }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        for (int i=0;i<3;i++)
            R[i]=0,G[i]=0,B[i]=0;
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int ret=k;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='R')R[i%3]++;
            else if (s[i]=='G')G[i%3]++;
            else B[i%3]++;
            if (i>=k)
            {
                int j=i-k;
                if (s[j]=='R')R[j%3]--;
                else if (s[j]=='G')G[j%3]--;
                else B[j%3]--;
            }
            if (i>=k-1)ret=min(ret,k-check());
        }
        cout<<ret<<endl;
    }
}