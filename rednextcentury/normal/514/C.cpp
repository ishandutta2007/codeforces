#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power[2000000][2];
ll b1 = 2707, b2 = 11411;
ll m1 = 99995999 , m2 = 99987373;
map<pair<ll,ll> ,int > mp;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int mx = 1e6;
    power[0][0]=power[0][1]=1;
    for (int i=1;i<=mx;i++){
        power[i][0] = (power[i-1][0]*b1)%m1;
        power[i][1] = (power[i-1][1]*b2)%m2;
    }
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) {
        string s;
        cin>>s;
        pair<ll,ll> H = {0,0};
        for (int j=0;j<s.size();j++) {
            H.first += power[j][0]*s[j];
            H.second+= power[j][1]*s[j];
            H.first%=m1;
            H.second%=m2;
        }
        mp[H]++;
    }
    for (int i=0;i<m;i++) {
        string s;
        cin>>s;
        pair<ll,ll> H = {0,0};
        for (int j=0;j<s.size();j++) {
            H.first += power[j][0]*s[j];
            H.second+= power[j][1]*s[j];
            H.first%=m1;
            H.second%=m2;
        }
        bool ok = 0;
        for (int j=0;j<s.size();j++) {
            for (char x='a';x<='c';x++) {
                if (x == s[j])continue;
                pair<ll,ll> cur = H;
                cur.first = ((cur.first - power[j][0]*s[j] + power[j][0]*x)%m1 + m1)%m1;
                cur.second = ((cur.second - power[j][1]*s[j] + power[j][1]*x)%m2 + m2)%m2;
                if (mp.count(cur))ok=1;
            }
            if (ok)break;
        }
        if (ok)puts("YES");
        else puts("NO");
    }
}