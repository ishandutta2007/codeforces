#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N=4002;
int n,P,mxT;
struct Item{
    int c,h;
} it[N]; vector<Item> vec[20000+10];

typedef pair< pair<int,int>, int> pii;
vector<pii> que;
int pre[N][N],suf[N][N],ans[20000+10];
int premp[20000+10],sufmp[20000+10];
int getAns(int l,int r,int x) {
    int res=0;
    for(int i=0;i<=x;i++) {
        res = max(res, pre[premp[r]][i]+suf[sufmp[l]][x-i]);
    }
    return res;
}
void solve(int l,int r,vector<pii> v) {
    if(l>r) return;
    //if(v.size()) printf("l=%d,r=%d\n", l,r);
    int mid = (l+r)>>1;
    int now=0; sufmp[mid+1] = 0;
    for(int i=mid;i>=max(l-P+1,1);i--) {
        for(auto item: vec[i]) {
            for(int j=4000;j>=0;j--) {
                suf[now+1][j] = suf[now][j];
                if(j>=item.c)suf[now+1][j] = max(suf[now+1][j],suf[now][j-item.c] + item.h);
            } ++ now;
        }
        sufmp[i] = now;
    } 
    //printf("suf [%d,%d]\n", mid,max(l-P+1,1));
    now = 0;  premp[mid] = 0;
    for(int i=mid+1;i<=r;i++) {
        for(auto item: vec[i]) {
            for(int j=4000;j>=0;j--) {
                pre[now+1][j] = pre[now][j];
                if(j>=item.c)pre[now+1][j] = max(pre[now+1][j],pre[now][j-item.c] + item.h);
            } ++ now;
        }
        premp[i] = now;
    }  
    //printf("pre [%d,%d]\n", mid+1,r);
    vector<pii> vL,vR;
    for(auto p: v) {
        // solve [mid,min(mid+P-1,r)]
        if(p.first.first < mid) vL.push_back(p);
        else if(p.first.first >= mid+P) vR.push_back(p);
        else 
        {
            ans[p.second] = getAns(max(p.first.first-P+1,1),p.first.first, p.first.second);
        }
    }
    solve(l,mid-1,vL); solve(mid+P,r,vR);
}
int main(){
    scanf("%d%d",&n,&P);
    for(int i=1;i<=n;i++){
        int c,h,t; scanf("%d%d%d",&c,&h,&t); mxT=max(mxT,t+P);
        vec[t].push_back((Item){c,h});
    }
    int q; scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        int a,b; scanf("%d%d",&a,&b);
        que.push_back(make_pair(make_pair(a,b),i));
    }
    sort(que.begin(),que.end());
    solve(1,mxT,que);
    for(int i=1;i<=q;i++) {
        printf("%d\n", ans[i]);
    }
}