#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ll long long
#define ff first
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
int use[N];
int main()
{
    sync;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int k1=0,k2=0;
    for (int i=0; i<s.size(); i++)
        if (i%2==0&&s[i]=='r') k1++; else
        if (i%2==1&&s[i]=='b') k2++;
    int ans=k1+k2-min(k1,k2);
    k1=0;
    k2=0;
    for (int i=0; i<s.size(); i++)
        if (i%2==0&&s[i]=='b') k1++; else
        if (i%2==1&&s[i]=='r') k2++;
    ans=min(ans,k1+k2-min(k1,k2));
    cout<<ans<<endl;
}