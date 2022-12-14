#include <bits/stdc++.h>
using namespace std;
long long num[100001][27];
void upd(string s,int id)
{
    char cur='a';
    long long p=0;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]==cur)
            p++;
        else
            num[id][cur-'a']=max(num[id][cur-'a'],p),cur=s[i],p=1;
    }
    num[id][cur-'a']=max(num[id][cur-'a'],p);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    upd(s,0);
    for (int i=1;i<n;i++)
    {
        cin>>s;
        char L = s[0];
        long long pre=0;
        char R = s[s.size()-1];
        for (auto x:s)
        {
            if (x==L)pre++;
            else break;
        }
        if (pre==s.size()) //ALL
        {
            num[i][L-'a']=num[i-1][L-'a']+pre+num[i-1][L-'a']*pre;
        }
        else
        {
            long long suf=0;
            for (int j=s.size()-1;j>=0;j--)
            {
                if (s[j]==R)suf++;
                else break;
            }
            if (L==R)
            {
                if (num[i-1][L-'a'])
                    num[i][L-'a']=max(num[i][L-'a'],pre+suf+1);
            }
            else
            {
                if (num[i-1][R-'a'])
                    num[i][R-'a']=max(num[i][R-'a'],suf+1);
                if (num[i-1][L-'a'])
                    num[i][L-'a']=max(num[i][L-'a'],pre+1);
            }
        }
        for (int j=0;j<26;j++)
            if (num[i-1][j])
                num[i][j]=max(num[i][j],1LL);
        upd(s,i);
    }
    long long mx=0;
    for (int i=0;i<26;i++)
        mx=max(mx,num[n-1][i]);
    cout<<mx<<endl;
}