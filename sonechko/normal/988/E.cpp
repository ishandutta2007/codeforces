#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;
const int MOD = 1e9 + 7;

int kol(string s, string t)
{
    if (t=="00")
    {
        int kk=-1;
        int res=0;
        for (int j=s.size()-1; j>=0; j--)
            if (s[j]=='0') {kk=j; break;}
        if (kk==-1) return 100000;
        while (kk!=s.size()-1)
        {
            res++;
            swap(s[kk],s[kk+1]);
            kk++;
        }
        kk=-1;
        for (int j=s.size()-2; j>=0; j--)
            if (s[j]=='0') {kk=j; break;}
        if (kk==-1) return 100000;
        while (kk!=s.size()-2)
        {
            res++;
            swap(s[kk],s[kk+1]);
            kk++;
        }
        return res;
    }
    if (t=="50")
    {
        int kk=-1;
        int res=0;
        for (int j=s.size()-1; j>=0; j--)
            if (s[j]=='0') {kk=j; break;}
        if (kk==-1) return 100000;
        while (kk!=s.size()-1)
        {
            res++;
            swap(s[kk],s[kk+1]);
            kk++;
        }
        kk=-1;
        for (int j=s.size()-2; j>=0; j--)
            if (s[j]=='5') {kk=j; break;}
        if (kk==-1) return 100000;
        if (s.size()>2&&kk==0)
        {
            int pp=-1;
            for (int j=1; j<s.size(); j++)
            if (s[j]!='0') {pp=j; break;}
            if (pp==-1) return 100000;
            while (pp!=1)
            {
                res++;
                swap(s[pp],s[pp-1]);
                pp--;
            }
        }
        while (kk!=s.size()-2)
        {
            res++;
            swap(s[kk],s[kk+1]);
            kk++;
        }
        return res;
    }
    int kk1=-1,kk2=-1;
    for (int j=s.size()-1; j>=0; j--)
    if (s[j]=='5') {kk1=j; break;}
    for (int j=s.size()-1; j>=0; j--)
    if (s[j]==t[0]) {kk2=j; break;}
    if (kk1==-1||kk2==-1) return 100000;
    int pp=-1;
    for (int d=0; d<s.size(); d++)
        if (s[d]!='0'&&d!=kk1&&d!=kk2) {pp=d; break;}
    if (s.size()>2&&pp==-1) return 100000;
    int res=0;
    while (pp>0)
    {
        res++;
        swap(s[pp],s[pp-1]);
        pp--;
    }
    int kk=-1;
    for (int j=s.size()-1; j>=0; j--)
    if (s[j]=='5') {kk=j; break;}
    while (kk!=s.size()-1)
    {
        res++;
        swap(s[kk],s[kk+1]);
        kk++;
    }
    kk=-1;
    for (int j=s.size()-2; j>=0; j--)
    if (s[j]==t[0]) {kk=j; break;}
    while (kk!=s.size()-2)
    {
        res++;
        swap(s[kk],s[kk+1]);
        kk++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int res=100000;
    int p=kol(s,"00");
    res=min(res,p);
    p=kol(s,"25");
    res=min(res,p);
    p=kol(s,"50");
    res=min(res,p);
    p=kol(s,"75");
    res=min(res,p);
    if (res==100000) cout<<"-1"<<endl; else cout<<res<<endl;
}