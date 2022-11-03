//
//  main.cpp
//  Water Tree
//
//  Created by  on 2019/10/20.
//  Copyright  2019 . All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nei[500005];
set<int> s;
int l[500005],r[500005],tmc;
int fa[500005];

void dfs(int now,int lst){
    l[now]=++tmc;
    fa[now]=lst;
    for(int i=0;i<nei[now].size();i++){
        if(nei[now][i]==lst){
            continue;
        }
        dfs(nei[now][i],now);
    }
    r[now]=++tmc;
    if(r[now]-l[now]==1){
        s.insert(l[now]);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    dfs(1,0);
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==3){
            set<int>::iterator it1=s.lower_bound(l[b]);
            set<int>::iterator it2=s.upper_bound(r[b]);
            if(it1!=it2){
                puts("0");
            }else{
                puts("1");
            }
        }else if(a==1){
            set<int>::iterator it1=s.lower_bound(l[b]);
            set<int>::iterator it2=s.upper_bound(r[b]);
            if(it1!=it2){
                s.insert(l[fa[b]]);
            }
            s.erase(it1,it2);
        }else{
            s.insert(l[b]);
        }
    }
    return 0;
}