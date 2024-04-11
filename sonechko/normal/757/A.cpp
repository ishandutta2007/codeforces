#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long MOD = 1e9 + 7;
#define mod %MOD
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ss second
#define ff first
#define ll long long
#define mp make_pair
#define endl "\n"
#define pb push_back
#define y1 ijdj
#define next lzk
#define tab difjke
int a[N];
int main()
{
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    #endif
    string s;
    cin>>s;
    int B=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]>='a'&&s[i]<='z') a[s[i]-'a']++; else
        if (s[i]=='B') B++;
    int ans=min(B,min(a['u'-'a']/2,a['l'-'a']));
    ans=min(ans,a['b'-'a']);
    ans=min(ans,a['a'-'a']/2);
    ans=min(ans,a['s'-'a']);
    ans=min(ans,a['r'-'a']);
    cout<<ans<<endl;
}