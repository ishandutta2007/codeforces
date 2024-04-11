#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

const int N = 1e6 + 11;

char a[N];
int mini[N*4],maxi[N*4],w[N*4];

void push(int i)
{
    mini[i+i]+=w[i];
    mini[i+i+1]+=w[i];
    maxi[i+i]+=w[i];
    maxi[i+i+1]+=w[i];
    w[i+i]+=w[i];
    w[i+i+1]+=w[i];
    w[i]=0;
}

void update(int i, int l, int r, int tl, int tr, int p)
{
    if (tl<=l&&r<=tr)
    {
        mini[i]+=p;
        maxi[i]+=p;
        w[i]+=p;
        return;
    }
    if (tl>r||l>tr) return;
    int mid=(l+r)/2;
    push(i);
    update(i+i,l,mid,tl,tr,p);
    update(i+i+1,mid+1,r,tl,tr,p);
    mini[i]=min(mini[i+i],mini[i+i+1]);
    maxi[i]=max(maxi[i+i],maxi[i+i+1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int p=1;
    int ks=0;
    for (int i=1; i<=n; i++)
    {
        char c;
        cin>>c;
        if (c=='L') p=max(1,p-1); else
        if (c=='R') p++; else
        {
            if (a[p]=='(') {ks--; update(1,1,n,p,n,-1);}
            if (a[p]==')') {ks++; update(1,1,n,p,n,+1);}
            a[p]=c;
            if (a[p]=='(') {ks++; update(1,1,n,p,n,+1);}
            if (a[p]==')') {ks--; update(1,1,n,p,n,-1);}
        }
        if (mini[1]<0||ks!=0) cout<<-1<<" ";
        else cout<<maxi[1]<<" ";
    }
}

/**
bal i
....(.....
    ------ +1
......)...
      ---- -1

min_bal >=0
last bal = 0
cout max_bal
**/