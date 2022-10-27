#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int NICO = 100005;
const int MAKI = 100005;
const int INF = 100007;
map<pii, int> mp;
map<int, pii> mp_;
vector<int> vec[4*NICO];
int a[4], b[NICO][4];
int k = 1, ans1, ans2;
int n, i, j, cnt = 0, boom=0;
ll max(ll x, ll y){return x<y?y:x;}
ll min(ll x, ll y){return x>y?y:x;}
void find(int x, int y, int z, int sta)
{
    if(sta==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(b[i][1]==x&&b[i][2]==y&&b[i][3]==z)
            {
                ans1 = i;
                boom = i;
                break;
            }
        }
    }
    
    if(sta==2)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==boom) continue;
            if(b[i][1]==x&&b[i][2]==y&&b[i][3]==z)
            {
                ans2 = i;
                break;
            }
        }
    }
    
}
int main()
{
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        for(j=1;j<=3;j++)
        {
            scanf("%d", &a[j]);
        }
        sort(a+1, a+4);
        for(j=1;j<=3;j++)
        {
            b[i][j] = a[j];
        }
        if(a[1]!=a[2] && a[2]!=a[3])
        {
            if(mp[make_pair(a[1], a[2])]==0)  mp[make_pair(a[1], a[2])] = ++cnt,mp_[cnt]=make_pair(a[1], a[2]);
            vec[mp[make_pair(a[1], a[2])]].push_back(a[3]);
    
            if(mp[make_pair(a[2], a[3])]==0)  mp[make_pair(a[2], a[3])] = ++cnt,mp_[cnt]=make_pair(a[2], a[3]);
            vec[mp[make_pair(a[2], a[3])]].push_back(a[1]);
        
            if(mp[make_pair(a[1], a[3])]==0)  mp[make_pair(a[1], a[3])] = ++cnt,mp_[cnt]=make_pair(a[1], a[3]);
            vec[mp[make_pair(a[1], a[3])]].push_back(a[2]);
        }
        
        if(a[1]==a[2] && a[2] != a[3])
        {
            if(mp[make_pair(a[1], a[2])]==0)  mp[make_pair(a[1], a[2])] = ++cnt,mp_[cnt]=make_pair(a[1], a[2]);
            vec[mp[make_pair(a[1], a[2])]].push_back(a[3]);
            
            if(mp[make_pair(a[2], a[3])]==0)  mp[make_pair(a[2], a[3])] = ++cnt,mp_[cnt]=make_pair(a[2], a[3]);
            vec[mp[make_pair(a[2], a[3])]].push_back(a[1]);
        }
        
        if(a[1]!=a[2] && a[2] == a[3])
        {
            if(mp[make_pair(a[1], a[2])]==0)  mp[make_pair(a[1], a[2])] = ++cnt,mp_[cnt]=make_pair(a[1], a[2]);
            vec[mp[make_pair(a[1], a[2])]].push_back(a[3]);
            
            if(mp[make_pair(a[2], a[3])]==0)  mp[make_pair(a[2], a[3])] = ++cnt,mp_[cnt]=make_pair(a[2], a[3]);
            vec[mp[make_pair(a[2], a[3])]].push_back(a[1]);
        }
        
        if(a[1] == a[2] && a[1] == a[3])
        {
            if(mp[make_pair(a[1], a[2])]==0)  mp[make_pair(a[1], a[2])] = ++cnt,mp_[cnt]=make_pair(a[1], a[2]);
            vec[mp[make_pair(a[1], a[2])]].push_back(a[3]);
        }
        
    }
    ll res = 0;

    for(i=1;i<=cnt;i++)
    {
        ll tmp = 0;
        sort(vec[i].begin(),vec[i].end());
        if(vec[i].size()==1)
        {
            tmp = max(vec[i][0], tmp);
            tmp = min(tmp, mp_[i].first);
            if(tmp>res)
            {
                k=1;
                a[1] = mp_[i].first;
                a[2] = mp_[i].second;
                a[3] = vec[i][0];
                sort(a+1,a+4);
                find(a[1],a[2],a[3],1);
            }
        }
        if(vec[i].size()>1)
        {
            int sz = vec[i].size();
            tmp = max(vec[i][sz-1] + vec[i][sz-2], tmp);
            tmp = min(tmp, mp_[i].first);
            if(tmp>res)
            {
                k=2;
                a[1] = mp_[i].first;
                a[2] = mp_[i].second;
                a[3] = vec[i][sz-1];
                sort(a+1,a+4);
                find(a[1],a[2],a[3],1);
                a[1] = mp_[i].first;
                a[2] = mp_[i].second;
                a[3] = vec[i][sz-2];
                sort(a+1,a+4);
                find(a[1],a[2],a[3],2);
            }
        }
        
        boom = 0;
        res = max(res, tmp);
    }
    
    cout << k << endl;
    if(k==1) cout << ans1 << endl;
    else
    {
        cout << ans1 << endl;
        cout << ans2 << endl;
    }
}