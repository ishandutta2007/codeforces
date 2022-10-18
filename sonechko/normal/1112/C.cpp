#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 1e6 + 11;

int a[N],b[N],kol[N],kk[N];
int m,k,n,s;

void up(int pos)
{
    for (int i=1; i<=1000000; i++)
        kk[i]=0;
    int tt=((pos-1)/k)*k;
    vector<int> del;
    for (int i=1; i<=pos-1-tt; i++)
        del.pb(i);
    int t=0;
    int poss=0;
    for (int i=pos; i<=m; i++)
    {
        if (kk[a[i]]<kol[a[i]]) {kk[a[i]]++; t++;}
        else del.pb(i);
        if (t==s) {poss=i; break;}
    }
    while (poss-pos+1<k)
    {
        poss++;
        del.pb(poss);
    }
    for (int p=1; p<=k-s; p++)
        del.pop_back();
    cout<<del.size()<<endl;
    for (int i=0; i<del.size(); i++)
        cout<<del[i]<<" ";
    cout<<endl;
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>m>>k>>n>>s;
    for (int i=1; i<=m; i++)
        cin>>a[i];
    for (int i=1; i<=s; i++)
    {
        int l;
        cin>>l;
        kol[l]++;
    }
    int pos=-1,t=0;
    for (int i=1; i<=m; i++)
    {
        if (kk[a[i]]<kol[a[i]]) t++;
        kk[a[i]]++;
        if (t==s) {pos=i; break;}
    }
    if (pos==-1) {cout<<"-1"; return 0;}
    if ((m-pos)/k+1>=n) up(1);
    for (int i=2; i<=m; i++)
    {
        kk[a[i-1]]--;
        if (kk[a[i-1]]<kol[a[i-1]]) t--;
        while (t<s&&pos<m)
        {
            pos++;
            if (kk[a[pos]]<kol[a[pos]]) t++;
            kk[a[pos]]++;
        }
        while (pos-i+1<k)
        {
            pos++;
            kk[a[pos]]++;
        }
        if (t==s&&pos<=m&&(i-1)/k+1+(m-pos)/k>=n) up(i);
    }
    cout<<-1<<endl;
}