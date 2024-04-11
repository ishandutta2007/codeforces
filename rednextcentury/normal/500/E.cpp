#include<bits/stdc++.h>
using namespace std;
#define mid (l+r)/2
#define L (x<<1)
#define R (L+1)
#define ll long long
map<int,int> mp;
set<int> ss;
int bk[1000000];
int S[1000000];
int E[1000000];
int EE[1000000];
int best[1000000];
int tree[5000000];
int nxt[500000][20];
int cost[500000][20];
void upd(int x,int l,int r,int v,int val){
    if (l==r)tree[x]=val;
    else {
        if (v<=mid)upd(L,l,mid,v,val);
        else upd(R,mid+1,r,v,val);
        tree[x]=max(tree[L],tree[R]);
    }
}
int query(int x,int l,int r,int s,int e){
    if (l>e || r<s)return 0;
    if (l>=s && r<=e)return tree[x];
    return max(query(L,l,mid,s,e),query(R,mid+1,r,s,e));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>S[i]>>EE[i];
        ss.insert(S[i]);
        ss.insert(S[i]+EE[i]);
    }
    int cur=0;
    for (auto x:ss){
        mp[x]=cur;
        bk[cur]=x;
        cur++;
    }
    for (int i=0;i<=cur;i++)E[i]=i;
    for (int i=1;i<=n;i++){
        EE[i] = mp[S[i]+EE[i]];
        S[i]=mp[S[i]];
        E[S[i]]=EE[i];
    }
    for (int i=cur;i>=0;i--){
        best[i]=max(E[i], query(1,0,cur,i,E[i]));
        upd(1,0,cur,i,best[i]);
        nxt[i][0] = min(cur,best[i]+1);
        cost[i][0] = bk[nxt[i][0]] - bk[best[i]];
    }
    for (int i=1;i<20;i++){
        for (int j=0;j<=cur;j++){
            nxt[j][i]=nxt[nxt[j][i-1]][i-1];
            cost[j][i]=cost[j][i-1]+cost[nxt[j][i-1]][i-1];
        }
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l = S[l];
        r = S[r];

        int cur = l;
        int ret=0;
        for (int i=19;i>=0;i--){
            if (best[cur]>=r){
                ret-=cost[cur][0];
                break;
            }
            if (nxt[cur][i]!=0 && best[nxt[cur][i]]<r){
                ret+=cost[cur][i];
                cur = nxt[cur][i];
            }
        }
        cout<<ret+cost[cur][0]<<endl;
    }
}