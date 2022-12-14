#include<bits/stdc++.h>
using namespace std;
#define ll long long
int l[1000000];
int r[1000000];
map<int,int> mp;
int pre[1000000];
int val[1000000];
int getCost(int l,int r){
    if (l==r && val[l]!=1)return 0;
    if (l==r)return -1;
    int cur = pre[r-1];
    cur-=pre[l];
    return cur;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--) {
        vector<pair<int,int> > events;
        int n;
        vector<int> all;
        mp.clear();
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d%d",&l[i],&r[i]);
            l[i]=l[i]*2+1,r[i]=r[i]*2+1;
            events.emplace_back(l[i],1);
            events.emplace_back(r[i]+1,-1);
            all.push_back(l[i]);
            all.push_back(r[i]);
            all.push_back(r[i]+1);
        }
        sort(events.begin(),events.end());
        all.push_back((int)-2e9 - 1);
        sort(all.begin(),all.end());
        int last = events[0].first;
        vector<pair<int,int> > changes;
        int cur = 0;
        int V=1;
        for (auto ev:events){
            int x = ev.first, p = ev.second;
            if (x!=last) {
                if (changes.empty() || cur!=changes.back().first){
                    changes.emplace_back(cur, x);
                    mp[x]=V++;
                }
            }
            if (p==1)cur++;
            else cur--;
            last = x;
        }
        mp[all[0]] = 0;
        for (int i=1;i<all.size();i++){
            if (mp.find(all[i])==mp.end())
                mp[all[i]]=mp[all[i-1]];
        }
        int mx=0;
        for (int i=1;i<=n;i++)l[i]=mp[l[i]],r[i]=mp[r[i]],mx=max(mx,r[i]);
        //for (int i=0;i<changes.size();i++)cout<<changes[i].first<<' ';
        //cout<<endl;
        for (int i=0;i<changes.size();i++)val[i]=changes[i].first;
        pre[0]=(val[0]==1);
        for (int i=1;i<changes.size();i++)pre[i]=(val[i]==1)+pre[i-1];
        int ok=0;
        int num=1;
        for (int i=0;i<changes.size();i++){
            if (val[i]>0)ok=1;
            if (val[i]==0 && ok)num++;
        }
        int ans=0;
        for (int i=1;i<=n;i++)/*cout<<l[i]<<' '<<r[i]<<endl,*/ans=max(ans, num+getCost(l[i],r[i]));
        cout<<ans<<endl;
        //cout<<"//////////////\n";
    }

}