#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MX=1e5+9;
const int sq=350;
int n,a[MX],block[MX];
deque<int>dq[MX];
int cnt[MX/sq + 10][MX];
void calc(int num){
    for(int i=0;i<dq[num].size();i++)cnt[num][dq[num][i]]++;
}
void clear_(int num){
    for(int i=0;i<dq[num].size();i++)cnt[num][dq[num][i]]--;
}
void solve(int l,int r){
    int bl=block[l];
    if(block[l]==block[r]){

        int last=dq[bl][l % sq];
        dq[bl][l % sq]=dq[bl][r % sq];

        for(int i=(l+1)%sq;i<=r%sq;i++){
            int newlast=dq[bl][i%sq];
            dq[bl][i % sq]=last;
            last=newlast;
        }
        return;
    }

    int R=block[r];
    int added=dq[R][r % sq];
    int L=block[l];
    cnt[L][added]++;
    cnt[R][added]--;
    vector<int>v;
    for(int i=0;i<dq[block[r]].size();i++){
        if(i==(r%sq))continue;
        v.push_back(dq[block[r]][i]);
    }
    dq[block[r]].clear();
    for(auto pp:v)dq[block[r]].push_back(pp);
    v.clear();

    for(int i=0;i<(l%sq);i++){
        v.push_back(dq[L][i]);
    }
    v.push_back(added);
    for(int i=(l%sq);i<dq[L].size();i++){
        v.push_back(dq[L][i]);
    }
    dq[L].clear();
    for(auto pp:v)dq[L].push_back(pp);
    v.clear();


    int last;
    int L1=block[l];
    while(L1<R){
        last=dq[ L1 ].back();
        dq[ L1 ].pop_back();
        cnt[L1][last]--;
        cnt[L1+1][last]++;
        dq[L1+1].push_front(last);
        L1++;
    }
}
int getcntnum(int l,int r,int x){
    int bl=block[l];
    int ans=0;
    if(block[l]==block[r]){
        for(int i=l;i<=r;i++){
            ans+=(dq[block[l]][i%sq]==x);
        }
        return ans;
    }

    while(block[l]==bl&&l<n){
        ans+=(dq[bl][l%sq] == x);
        l++;
    }

    bl = block[r];

    while(block[r]==bl&&r){
        ans+=(dq[bl][r%sq] == x);
        r--;
    }

    int L=block[l],R=block[r];
    while(L<=R){
        ans+=cnt[L][x];
        L++;
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        int block1=i/sq;

        dq[block1].push_back(a[i]);

        cnt[block1][a[i]]++;

        block[i]=i/sq;
    }
    int ans=0;
    int q;cin>>q;
    while(q--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int l,r;
            scanf("%d%d",&l,&r);

            l=(l+ans-1)%n;
            r=(r+ans-1)%n;

            if(l>r)swap(l,r);

            solve(l,r);
        }
        else{
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            l=(l+ans-1)%n;
            r=(r+ans-1)%n;

            if(l>r)swap(l,r);

            x=(x+ans-1)%n;x++;

            ans=getcntnum(l,r,x);
            printf("%d\n",ans);
        }
    }
}