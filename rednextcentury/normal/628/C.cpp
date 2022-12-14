#include<bits/stdc++.h>
using namespace std;
long long dp[1000001][5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string ss;
    for (int i=0;i<n;i++)
    {
        if (s[i]-'a' > 'z'-s[i])
        {
            if (k>=s[i]-'a')
                ss+='a',k-=s[i]-'a';
            else
                ss+=s[i]-k,k=0;
        }
        else
        {
            if (k>='z'-s[i])
                ss+='z',k-='z'-s[i];
            else
                ss+=s[i]+k,k=0;
        }
    }
    if (k==0)
        cout<<ss<<endl;
    else
        cout<<-1<<endl;
}