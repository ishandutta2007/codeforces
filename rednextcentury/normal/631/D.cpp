#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,char> > k;
vector<pair<long long,char> > s;
vector<pair<long long,char> > sec;
int p[2000000];
int n, m;
void PRE()
{
    int i = 0, j = -1;
    p[0] = -1;
    while (i < n)
    {
        while (j >= 0 && k[j] != k[i])
            j = p[j];
        i++,j++;
        p[i] = j;
    }
}
bool match[2000000];
void KMP()
{
    int j = 0;
    for (int i=0; i<m;)
    {
        if (k[j] == s[i])
        {

            j++;
            if (j == n)
            {
                j = p[j];
                match[i] = 1;
            }
            i++;
        }
        else if (j>0)
            j = p[j];
        else
            i++;
    }
}
int main()
{
    int l1,l2;
    cin>>l1>>l2;
    char cur='(';
    long long num=0;
    for (int i=0;i<l1;i++)
    {
        char x;int l;
        scanf("%d-%c",&l,&x);
        if (cur==x)
            num+=l;
        else
        {
            if (cur!='(')
            s.push_back(make_pair(num,cur));
            cur=x;
            num=l;
        }
    }
    if (cur!='(')
    s.push_back(make_pair(num,cur));
    cur='(';
    num=0;
    for (int i=0;i<l2;i++)
    {
        char x;int l;
        scanf("%d-%c",&l,&x);
        if (cur==x)
            num+=l;
        else
        {
             if (cur!='(')
            sec.push_back(make_pair(num,cur));
            cur=x;
            num=l;
        }
    }
     if (cur!='(')
    sec.push_back(make_pair(num,cur));
    for (int i=1;i<sec.size()-1;i++)
        k.push_back(sec[i]);
    n=k.size();
    m=s.size();

    long long ans=0;
    if (sec.size()==1)
    {
        for (int i=0;i<m;i++)
        {
            if (s[i].second==sec[0].second)
            {
                ans+=(max(0LL,s[i].first-sec[0].first+1));
            }
        }
    }
    else if (sec.size()==2)
    {
        for (int i=1;i<m;i++)
        {
            if (s[i].second==sec[1].second && s[i-1].second==sec[0].second && s[i].first>=sec[1].first && s[i-1].first>=sec[0].first)
                ans++;
        }
    }
    else
    {
        PRE();
        KMP();
        for (int i=k.size();i<m-1;i++)
        {
            if (match[i])
            {
                if (s[i-k.size()].second==sec[0].second && s[i+1].second==sec[sec.size()-1].second && s[i+1].first>=sec[sec.size()-1].first &&s[i-k.size()].first>=sec[0].first)
                    ans++;
            }
        }
    }
    cout<<ans<<endl;
}