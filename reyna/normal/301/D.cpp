//In the name of God
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn = 2e5 + 1e3;
int place[Maxn];
int arr[Maxn];
int ans[Maxn];
bool mark[Maxn];
int t[4 * Maxn],id[4 * Maxn],is_leaf[4 * Maxn];
pair<int,pair<int,int> > do_query[Maxn * 3];
int n,m;
void build(int v = 1,int b = 0,int e = n-1){
    if(b == e){
        id[b] = v;
        is_leaf[v] = 1;
        return;
    }
    int mid = b + e >> 1,l = v << 1,r = l | 1;
    build(l,b,mid);
    build(r,mid+1,e);
    return;
}
void update(int v,int x){
    if(!v)
        return;
    t[v]+=x;
    update(v >> 1,x);
    return;
}
int query(int i,int j,int v = 1,int b = 0,int e = n-1){
    if(e < i || b > j)
        return 0;
    if(i <= b && e <= j)
        return t[v];
    int mid = b + e >> 1,l = v << 1,r = l | 1;
    return query(i,j,l,b,mid) + query(i,j,r,mid+1,e);
}
int main(){
    int x = 0;
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n;i++){
        scanf("%d",&arr[i]);
        place[arr[i]] = i;
    }
    for(int i = 0; i < n;i++){
        do_query[x++] = make_pair(i,make_pair(-1,arr[i]));
    }
    for(int i = 0; i < m;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        --l,--r;
        do_query[x++] = make_pair(r,make_pair(i,l));
    }
    build();
    sort(do_query,do_query+x);
    for(int i = 0; i < x;i++){
        int t = do_query[i].second.first;
        if(t == -1){
            int val = do_query[i].second.second;
            mark[val] = 1;
            for(int j = 1; j * j <= val;j++){
                if(val % j == 0){
                    if(mark[j])
                        update(id[place[j]],1);
                    if(mark[val/j])
                        if(j * j != val)
                            update(id[place[val/j]],1);
                }
            }
            for(int j = 2 * val; j <= n;j+=val)
                if(mark[j])
                    update(id[place[j]],1);
        }else{
            int l = do_query[i].second.second,r = do_query[i].first;
            ans[t] = query(l,r);
        }
    }
    for(int i = 0; i < m;i++)
        printf("%d\n",ans[i]);
    return 0;
}