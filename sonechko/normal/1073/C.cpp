#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

const int N = 5e5 + 11;

int n;
string s;
int x,y;
pair<int,int> pos1[N],pos2[N];

bool good(int t)
{
    for (int i=1; i<=n-t+1; i++)
    {
        pair<int,int> p1=pos1[i-1];
        pair<int,int> p2=pos2[i+t];
        //cout<<t<<" "<<i<<" "<<p1.ff<<" "<<p1.ss<<" -> "<<p2.ff<<" "<<p2.ss<<endl;
        if (abs(p1.ff-p2.ff)+abs(p1.ss-p2.ss)<=t) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    s="."+s;
    cin>>x>>y;
    int p=x+y;
    if (p<0) p+=2000000000;
    if (p%2!=(n)%2)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        pos1[i]=pos1[i-1];
        if (s[i]=='U') pos1[i].ss++;
        if (s[i]=='D') pos1[i].ss--;
        if (s[i]=='L') pos1[i].ff--;
        if (s[i]=='R') pos1[i].ff++;
    }
    pos2[n+1]=mp(x,y);
    for (int i=n; i>=1; i--)
    {
        pos2[i]=pos2[i+1];
        if (s[i]=='U') pos2[i].ss--;
        if (s[i]=='D') pos2[i].ss++;
        if (s[i]=='L') pos2[i].ff++;
        if (s[i]=='R') pos2[i].ff--;
    }
    int l=0,r=n;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) cout<<l<<endl; else
    if (good(r)) cout<<r<<endl; else cout<<-1<<endl;
}