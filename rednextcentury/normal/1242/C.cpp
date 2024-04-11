#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<int,int> loc;
int n;
vector<int> vec[100000];
vector<pair<int,int> > tot;
ll cur[10000];
int can[1000000];
vector<pair<int,pair<int,int> > > ops[1000000];
ll need;
bool dp[1000000];
int back[1000000];
pair<int,int> ret[100000];
void GetCycle(int id,int x) {
    int org = id;
    int mask = 0;
    ll take = x;
    vector<pair<int,pair<int,int> > > op;
    while(1){
        mask|=(1<<id);
        ll S = cur[id] - take;
        ll o = need - S;
        if (loc.find(o)==loc.end())return;
        int pos = loc[o];
        if (pos == org && o==x) {
            op.push_back({org,{o,id}});
            break;
        }
        if (mask&(1<<pos))return;
        op.push_back({pos,{o,id}});
        id = pos;
        take = o;
    }
    if (can[mask])return;
    can[mask]=1;
    ops[mask] = op;
    dp[mask]=1;
    back[mask]=0;
}
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    scanf("%d",&n);
    ll sum = 0;
    for (int i=0;i<n;i++) {
        int k;
        scanf("%d",&k);

        for (int j=0;j<k;j++) {
            int x;
            scanf("%d",&x);
            cur[i]+=x;
            sum+=x;
            vec[i].push_back(x);
            tot.emplace_back(i,x);
            loc[x]=i;
        }
    }
    if (sum%n) {
        printf("No\n");
        return 0;
    }
    need = sum/n;
    for (int i=0;i<tot.size();i++) {
        GetCycle(tot[i].first,tot[i].second);
    }
    dp[0]=1;
    for (int mask=1;mask<(1<<n);mask++){
        for(int sub = mask; sub > 0; sub = (sub-1) & mask){
            if (can[sub] && dp[mask-sub]){
                dp[mask]=1;
                back[mask]=mask-sub;
                break;
            }
        }
    }
    if (dp[(1<<n)-1]){
        printf("Yes\n");
        int mask = (1<<n)-1;
        vector<int> ans;
        while(mask!=0) {
            ans.push_back(mask-back[mask]);
            mask=back[mask];
        }
        for (auto x:ans) {
            for (auto p:ops[x]) {
                ret[p.first] = p.second;
            }
        }
        for (int i=0;i<n;i++){
            printf("%d %d\n",ret[i].first,ret[i].second+1);
        }
        return 0;
    } else {
        printf("No\n");
    }
}