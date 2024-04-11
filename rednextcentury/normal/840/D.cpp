#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000000];
vector<int> vec[1000000];
int Count(int x,int l,int r) {return upper_bound(vec[x].begin(),vec[x].end(),r) - lower_bound(vec[x].begin(),vec[x].end(),l);}
bool isValid(int x,int l,int r,int k) {return (Count(x,l,r)>((r-l+1) / k));}
int candidates[1000000][11];
int findAnswer(int id,int l,int r,int k) {
    int ret = 1e9;
    for (int i=0;i<10;i++) {if (isValid(candidates[id][i],l,r,k))ret=min(ret,candidates[id][i]);}
    if (ret>=1e8)ret=-1;
    return ret;
}
int cur[1000000][11];
int cnt[1000000];
int K=5;
void calcCandidates(vector<pair<pair<int,int>,pair<int,int> > > &Q, int l, int r) {
    if (l>r)return;
    if (Q.empty())return;
    int mid = (l+r)/2;
    vector<pair<pair<int,int>,pair<int,int> > > L,R;
    for (int i=mid+1;i<=r;i++) {
        cnt[a[i]]++;
        int mn = 1e9, id = -1 , ok=0;
        for (int j=0;j<K;j++){
            cur[i][j]=cur[i-1][j];
            if (cur[i][j]==a[i])ok=1;
            if (cnt[cur[i][j]]<mn)mn=cnt[cur[i][j]],id=j;
        }
        if (ok)continue;
        if (cnt[a[i]]>mn) cur[i][id]=a[i];
    }
    for (int i=mid+1;i<=r;i++)cnt[a[i]]=0;
    for (int i=mid;i>=l;i--) {
        cnt[a[i]]++;
        int mn = 1e9, id = -1 , ok=0;
        for (int j=0;j<K;j++){
            cur[i][j]=cur[i+1][j];
            if (cur[i][j]==a[i])ok=1;
            if (cnt[cur[i][j]]<mn)mn=cnt[cur[i][j]],id=j;
        }
        if (ok)continue;
        if (cnt[a[i]]>mn) cur[i][id]=a[i];
    }
    for (int i=mid;i>=l;i--)cnt[a[i]]=0;
    for (auto q:Q) {
        if (q.second.second < mid) L.push_back(q);
        else if (q.second.first > mid) R.push_back(q);
        else {
            int l = q.second.first;
            int r = q.second.second;
            int k = q.first.second;
            int id = q.first.first;
            for (int i=0;i<K;i++)candidates[id][i]=cur[l][i];
            for (int i=0;i<K;i++)candidates[id][i+K]=cur[r][i];
        }
    }
    calcCandidates(L,l,mid-1);
    calcCandidates(R,mid+1,r);
}
int L[1000000];
int R[1000000];
int kk[1000000];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]),vec[a[i]].push_back(i);

    vector<pair<pair<int,int>,pair<int,int> > > Q;
    for (int i=1;i<=q;i++) {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        L[i]=l,R[i]=r,kk[i]=k;
        Q.push_back({{i,k},{l,r}});
    }
    calcCandidates(Q,1,n);
    for (int i=1;i<=q;i++) {
        printf("%d\n",findAnswer(i,L[i],R[i],kk[i]));
    }
}