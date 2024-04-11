#include<bits/stdc++.h>
using namespace std;
int num[2001][2001];
int mx[2001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for (int j=0;j<m;j++)
        {
            num[j][s[j]-'A']++;
            if (num[j][s[j]-'A']>mx[j])mx[j]=num[j][s[j]-'A'];
        }
    }
    long long ret=0;
    for (int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        ret+=x*mx[i];
    }
    cout<<ret<<endl;
}