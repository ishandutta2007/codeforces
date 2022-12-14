#include<bits/stdc++.h>
using namespace std;
int num[11];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        string ret="";
        bool ok=1;
        for (int i=0;i<10;i++)num[i]=0;
        for (int i=n-1;i>=0;i--)
        {
            ret+="=";
        }
        reverse(ret.begin(),ret.end());
        if (ok)
        {
            for (int i=0;i<10;i++)num[i]=0;
            for (int i=n-1;i>=0;i--)
            {
                int cur=1;
                int pp = s[i]-'0';
                for (int j=pp-1;j>=0;j--)
                    cur=max(cur,num[j]+1);
                num[s[i]-'0']=max(num[s[i]-'0'],cur);
                if (cur>2)ok=0;
                if (cur==2)ret[i]='2';
            }
            for (int i=0;i<10;i++)num[i]=0;
            for (int i=0;i<n;i++)
            {
                int cur=1;
                int pp = s[i]-'0';
                for (int j=pp+1;j<10;j++)
                    cur=max(cur,num[j]+1);
                num[s[i]-'0']=max(num[s[i]-'0'],cur);
                if (cur>2)ok=0;
                if (cur==2)ret[i]='1';
            }
            int mn2=13;
            for (int i=0;i<n;i++)
            {
                if (ret[i]=='2')mn2=min(mn2,s[i]-'0');
                if (ret[i]=='=' && mn2<=s[i]-'0')
                    ret[i]='2';
                else if (ret[i]=='=')ret[i]='1';
            }
        }
        if (!ok){
            cout<<"-\n";
            continue;
        }
        string t="";
        for (int i=0;i<n;i++)
        {
            if (ret[i]=='1')t+=s[i];
        }
        for (int i=0;i<n;i++)
        {
            if (ret[i]=='2')t+=s[i];
        }
        for (int i=1;i<n;i++)
        {
            if (t[i]<t[i-1])ok=0;
        }
        if (!ok){
            cout<<"-\n";
            continue;
        }
        else cout<<ret<<"\n";
    }
}