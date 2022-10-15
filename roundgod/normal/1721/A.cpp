#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
string s,t;
map<char,int> mp;
int main()
{
    cin>>T;
    while(T--)
    {
        mp.clear();
        cin>>s; cin>>t;
        mp[s[0]]++; mp[s[1]]++; mp[t[0]]++; mp[t[1]]++;
        if(mp.size()==2)
        {
            puts("1");
        }
        else printf("%d\n",(int)mp.size()-1);
    }
    return 0;
}