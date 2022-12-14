#include<bits/stdc++.h>
using namespace std;
int L[1000000];
int R[1000000];
int S[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s="."+s;
    int cur=0;
    L[0]=n+10;
    R[n+1]=n+10;
    for (int i=1;i<=n;i++)
    {
        if (s[i]=='(')cur++;
        else cur--;
        L[i]=min(cur,L[i-1]);
        S[i]=cur;
    }
    for (int i=n;i>=1;i--)
        R[i]=min(R[i+1],S[i]);
    int ret=0;
    for (int i=1;i<=n;i++)
    {
        int curSum = S[n];
        if (s[i]=='(')curSum-=2;
        else curSum+=2;
        if (curSum!=0)continue;
        if (L[i-1]>=0 && R[i]+2>=0 && s[i]==')')ret++;
        if (L[i-1]>=0 && R[i]-2>=0 && s[i]=='(')ret++;
    }
    cout<<ret<<endl;
}