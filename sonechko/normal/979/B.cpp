#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ss second
#define ull unsigned long long
#define mp make_pair
#define ll long long
const int N = 4e5 + 11;
const int MOD = 1e9 + 9;

int k1[N],k2[N],k3[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    if (s[i]>='A'&&s[i]<='Z') k1[s[i]-'A']++; else k1[s[i]-'a'+27]++;
    int i1=0;
    for (int i=0; i<=100; i++)
    if (k1[i]>k1[i1]) i1=i;
    int nn=n;
    int res1;
    if (k1[i1]==(int)s.size())
    {
              if (n==1) res1=k1[i1]-1; else res1=k1[i1];
    } else
    {
    for (int i=0; i<=100; i++)
    if (i!=i1)
    {
              int p=min(nn,k1[i]);
              k1[i1]+=p;
              nn-=p;
    }
    res1=k1[i1];
    }
    for (int i=0; i<=100; i++)
    k1[i]=0;

    cin>>s;
    for (int i=0; i<s.size(); i++)
    if (s[i]>='A'&&s[i]<='Z') k1[s[i]-'A']++; else k1[s[i]-'a'+27]++;
    i1=0;
    for (int i=0; i<=100; i++)
    if (k1[i]>k1[i1]) i1=i;
    nn=n;
    int res2;
    if (k1[i1]==(int)s.size())
    {
              if (n==1) res2=k1[i1]-1; else res2=k1[i1];
    } else
    {
    for (int i=0; i<=100; i++)
    if (i!=i1)
    {
              int p=min(nn,k1[i]);
              k1[i1]+=p;
              nn-=p;
    }
    res2=k1[i1];
    }
    for (int i=0; i<=100; i++)
    k1[i]=0;

    cin>>s;
    for (int i=0; i<s.size(); i++)
    if (s[i]>='A'&&s[i]<='Z') k1[s[i]-'A']++; else k1[s[i]-'a'+27]++;
    i1=0;
    for (int i=0; i<=100; i++)
    if (k1[i]>k1[i1]) i1=i;
    nn=n;
    int res3;
    if (k1[i1]==(int)s.size())
    {
              if (n==1) res3=k1[i1]-1; else res3=k1[i1];
    } else
    {
    for (int i=0; i<=100; i++)
    if (i!=i1)
    {
              int p=min(nn,k1[i]);
              k1[i1]+=p;
              nn-=p;
    }
    res3=k1[i1];
    }
    for (int i=0; i<=100; i++)
    k1[i]=0;

    if (res1>res2&&res1>res3) cout<<"Kuro"<<endl; else
    if (res2>res1&&res2>res3) cout<<"Shiro"<<endl; else
    if (res3>res1&&res3>res2) cout<<"Katie"<<endl; else cout<<"Draw"<<endl;
}