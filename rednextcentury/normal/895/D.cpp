#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long P(long long a,long long b)
{
    if (b==0)return 1;
    long long x =P(a,b/2);
    x=(x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
long long inv(long long x){return P(x,mod-2);}
long long Inv[1000001];
long long F[1000001];
long long cur[26];
long long V;
void gg()
{
    int num=0;
    long long B=1;
    for (int i=0;i<26;i++)
        B=(B*F[cur[i]])%mod,num+=cur[i];
    long long ret = F[num];
    ret=(ret*inv(B))%mod;
    V=ret;
}
long long cnt[26];
string getMin(string s)
{
    for (int i=s.size()-1;i>=0;i--)
    {
        int best=-1;
        for (int j=s[i]-'a'+1;j<26;j++)
        {
            if (cnt[j])
            {
                best=j;
                break;
            }
        }
        if (best!=-1)
        {
            cnt[s[i]-'a']++;
            cnt[best]--;
            s[i]=char(best+'a');
            for (int j=i+1;j<s.size();j++)
            {
                int mn=0;
                for (int x=0;x<26;x++)
                {
                    if (cnt[x])
                    {
                        cnt[x]--;
                        mn=x;
                        break;
                    }
                }
                s[j]=char(mn+'a');
            }
            return s;
        }
        cnt[s[i]-'a']++;
    }
    return "-";
}
string getMax(string a,string s)
{
    int last=-1;
    for (int i=0;i<s.size();i++)
    {
        for (int j=0;j<s[i]-'a';j++)
        {
            if (cur[j])
            {
                last=i;
                break;
            }
        }
        if (cur[s[i]-'a'])
            cur[s[i]-'a']--;
        else break;
    }
    if (last==-1)return "-";
    for (int i=0;i<26;i++)cur[i]=0;
    for (auto x:a)cur[x-'a']++;
    string mx="";
    for (int i=0;i<last;i++)
    {
        mx+=s[i];
        cur[s[i]-'a']--;
    }
    for (int i=s[last]-'a'-1;i>=0;i--)
    {
        if (cur[i])
        {
            cur[i]--;
            mx+=char(i+'a');
            break;
        }
    }
    for (int i=last+1;i<a.size();i++)
    {
        int bb=0;
        for (int j=25;j>=0;j--)
        {
            if (cur[j])
            {
                cur[j]--;
                bb=j;
                break;
            }
        }
        mx+=char(bb+'a');
    }
    return mx;
}
long long getNum(string s)
{
    long long ret=0;
    for (int i=0;i<26;i++)cur[i]=0;
    for (auto x:s)cur[x-'a']++;
    gg();
    int len=s.size();
    for (int i=0;i<s.size();i++)
    {
        long long ppp=inv(len);
        for (int j=0;j<s[i]-'a';j++)
        {
            if (cur[j]==0)continue;
            long long X = V;
            X = (X*ppp)%mod;
            X = (X*F[cur[j]])%mod;
            cur[j]--;
            X = (X*Inv[cur[j]])%mod;
            ret+=X;
            ret%=mod;
            cur[j]++;
        }
        V = (V*ppp)%mod;
        V = (V*F[cur[s[i]-'a']])%mod;
        cur[s[i]-'a']--;
        V = (V*Inv[cur[s[i]-'a']])%mod;
        len--;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a>>b;
    F[0]=1;
    Inv[0]=inv(1);
    for (int i=1;i<=1000000;i++)
    {
        F[i]=(F[i-1]*i)%mod;
        Inv[i]=inv(F[i]);
    }
    for (auto x:a)cur[x-'a']++;
    string s2 = getMax(a,b);
    string s1 = getMin(a);
    if (s1=="-" || s2=="-")
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<(getNum(s2)-getNum(s1)+1+mod)%mod<<endl;
}