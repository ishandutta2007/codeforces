//
//  main.cpp
//  ReadTime
//
//  Created by  on 2019/10/20.
//  Copyright  2019 . All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int n,m;
long long h[100005];
long long p[100005];

bool check(long long mid){
    int l=1;
    for(int i=1;i<=n;i++){
        long long dis=h[i]-p[l];
        if(dis<0){
            dis=0;
        }
        if(dis>mid){
            return 0;
        }
        if(dis<=mid/3){
            long long go=mid-dis*2;
            l=upper_bound(p+1,p+m+1,go+h[i])-p;
        }else{
            long long go=(mid-dis)/2;
            l=upper_bound(p+1,p+m+1,go+h[i])-p;
        }
        if(l>m){
            break;
        }
    }
    if(l<=m){
        return 0;
    }
    return 1;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",h+i);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",p+i);
    }
    long long l=-1,r=1e18;
    while(r-l>1){
        long long m=(l+r)>>1;
        if(check(m)){
            r=m;
        }else{
            l=m;
        }
    }
    printf("%lld\n",r);
    return 0;
}