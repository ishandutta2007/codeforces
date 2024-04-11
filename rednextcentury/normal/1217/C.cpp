#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll zeros[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        zeros[0]=(s[0]=='0');
        for (int i=1;i<s.size();i++)
        {
            if (s[i]=='0')zeros[i]=zeros[i-1]+1;
            else zeros[i]=0;
        }
        int n=s.size();
        ll ret=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='1')
            {
                ll last=0;
                if (i)last=zeros[i-1];
                ll cur=0;
                for (int j=i;j<min(i+20,n);j++)
                {
                    cur=cur*2+(s[j]-'0');
                    ll len = j-i+1;
                    if (cur>=len && cur<=len+last)
                        ret++;
                }
            }
        }
        cout<<ret<<endl;
    }
}