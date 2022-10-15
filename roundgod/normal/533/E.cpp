#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s,t;
int main()
{
    scanf("%d",&n);
    cin>>s; cin>>t;
    int ans=0;
    int x=0,y=0,now=0;
    while(now<n&&s[now]==t[now]) now++;
    assert(now!=n);
    int l=now,r=now+1;
    while(l<n&&r<n&&s[l]==t[r]) l++,r++;
    if(r==n) ans++;
    else
    {
        l++;
        while(l<n&&r<n&&s[l]==t[r]) l++,r++;
        if(l==n) ans++;
    }
    swap(s,t);
    x=0,y=0,now=0;
    while(now<n&&s[now]==t[now]) now++;
    assert(now!=n);
    l=now,r=now+1;
    while(l<n&&r<n&&s[l]==t[r]) l++,r++;
    if(r==n) ans++;
    else
    {
        l++;
        while(l<n&&r<n&&s[l]==t[r]) l++,r++;
        if(l==n) ans++;
    }
    printf("%d\n",ans);
    return 0;
}