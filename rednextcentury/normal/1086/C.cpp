#include<bits/stdc++.h>
using namespace std;
int k;
string TryDown(string s,string a,string b)
{
    char mp[27];
    bool vis[27]={0};
    for (int i=0;i<26;i++)
        mp[i]='5';
    bool A=1,B=1;
    for (int i=0;i<a.size();i++)
    {
        if (mp[s[i]-'a']!='5')
        {
            if (A && mp[s[i]-'a']<a[i])
                return "NO";
            if (B && mp[s[i]-'a']>b[i])
                return "NO";
            if (mp[s[i]-'a']>a[i])A=0;
            if (mp[s[i]-'a']<b[i])B=0;
        }
        else
        {
            int L = A?(a[i]-'a'):-1;
            int R = B?(b[i]-'a'):k;
            bool ok=0;
            for (int j=L+1;j<R;j++)
            {
                if (!vis[j])
                {
                    vis[j]=1;
                    mp[s[i]-'a']=char(j+'a');
                    ok=1;
A=0,B=0;
                    break;
                }
            }
            if (!ok)
            {
                if (L==-1)L++;
                if (R==k)R--;
                if (!vis[L])
                {
if(L!=R)
B=0;
                    vis[L]=1;
                    mp[s[i]-'a']=char('a'+L);
                }
                else if (!vis[R])
                {
if(L!=R)
A=0;
                    vis[R]=1;
                    mp[s[i]-'a']=char('a'+R);
                }
                else
                    return "NO";
            }
        }
    }
    string ret="";
    for (int i=0;i<k;i++)
    {
        if (mp[i]=='5')
        {
            for (int j=0;j<k;j++)
            {
                if (!vis[j])
                {
                    vis[j]=1;
                    mp[i]=char(j+'a');
                    break;
                }
            }
        }
        ret+=mp[i];
    }
    return ret;
}
string TryUp(string s,string a,string b)
{
    char mp[27];
    bool vis[27]={0};
    for (int i=0;i<26;i++)
        mp[i]='5';
    bool A=1,B=1;
    for (int i=0;i<a.size();i++)
    {
        if (mp[s[i]-'a']!='5')
        {
            if (A && mp[s[i]-'a']<a[i])
                return "NO";
            if (B && mp[s[i]-'a']>b[i])
                return "NO";
            if (mp[s[i]-'a']>a[i])A=0;
            if (mp[s[i]-'a']<b[i])B=0;
        }
        else
        {
            int L = A?(a[i]-'a'):-1;
            int R = B?(b[i]-'a'):k;
            bool ok=0;
            for (int j=L+1;j<R;j++)
            {
                if (!vis[j])
                {
                    vis[j]=1;
                    mp[s[i]-'a']=char(j+'a');
                    ok=1;
A=0,B=0;
                    break;
                }
            }
            if (!ok)
            {
                if (L==-1)L++;
                if (R==k)R--;
                if (!vis[R])
                {
                    vis[R]=1;
if(L!=R)
A=0;
                    mp[s[i]-'a']=char('a'+R);
                }
                else if (!vis[L])
                {
                    vis[L]=1;
if(L!=R)
B=0;
                    mp[s[i]-'a']=char('a'+L);
                }
                else
                    return "NO";
            }
        }
    }
    string ret="";
    for (int i=0;i<k;i++){
        if (mp[i]=='5')
        {
            for (int j=0;j<k;j++)
            {
                if (!vis[j])
                {
                    vis[j]=1;
                    mp[i]=char(j+'a');
                    break;
                }
            }
        }
        ret+=mp[i];
    }
    return ret;
}
int main()
{

    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>k;
        string s,a,b;
        cin>>s>>a>>b;
        string L = TryDown(s,a,b);
        string R = TryUp(s,a,b);
        if (L!="NO")
            cout<<"YES\n"<<L<<"\n";
        else if (R!="NO")
            cout<<"YES\n"<<R<<"\n";
        else
            cout<<"NO\n";
    }
}