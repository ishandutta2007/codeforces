#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ff first
#define ll long long
#define ss second
const ll N = 1e6 + 11;

ll st[N];
string p1,p2,p3,poch;
char g(int n, ll k)
{
    if (n==0) return poch[k-1];
    if (p1.size()>=k) return p1[k-1];
    if (p1.size()+st[n-1]>=k) return g(n-1,k-p1.size());
    if (p1.size()+st[n-1]+p2.size()>=k) return p2[k-p1.size()-st[n-1]-1];
    if (p1.size()+st[n-1]+p2.size()+st[n-1]>=k) return g(n-1,k-p1.size()-st[n-1]-p2.size());
    return p3[k-p1.size()-st[n-1]-p2.size()-st[n-1]-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q;
    cin>>q;
    poch="What are you doing at the end of the world? Are you busy? Will you save us?";
    p1="What are you doing while sending *";
    p2="*? Are you busy? Will you send *";
    p3="*?";
    st[0]=poch.size();
    for (int i=1; i<=100000; i++)
    {
        st[i]=p1.size()+st[i-1]+p2.size()+st[i-1]+p3.size();
        st[i]=min(st[i],2000000000000000000);
    }
    for (int jj=1; jj<=q; jj++)
    {
        int n;
        ll k;
        cin>>n>>k;
        if (k>st[n]) cout<<"."; else
        {
            char ch=g(n,k);
            if (ch=='*') cout<<'"';
            else cout<<g(n,k);
        }
    }
}