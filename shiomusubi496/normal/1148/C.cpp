#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n; scanf("%lld",&n);
    vector<int> p(n);
    vector<int> a,b;
    for(int i=0;i<n;i++){
        scanf("%lld",&p[i]); p[i]--;
        if(i<n/2 && p[i]>=n/2)a.push_back(i);
        if(i>=n/2 && p[i]<n/2)b.push_back(i);
    }
    vector<pair<int,int>> ans;
    for(int i=0;i<a.size();i++){
        if(a[i]+n/2<=b[i]){
            ans.push_back({a[i],b[i]}); swap(p[a[i]],p[b[i]]);
        }
        else{
            ans.push_back({a[i],n-1}); swap(p[a[i]],p[n-1]);
            ans.push_back({n-1,0}); swap(p[n-1],p[0]);
            ans.push_back({0,b[i]}); swap(p[0],p[b[i]]);
            ans.push_back({a[i],n-1}); swap(p[a[i]],p[n-1]);
        }
    }
    vector<int> q(n);
    for(int i=0;i<n;i++)q[p[i]]=i;
    for(int i=0;i<n/2;i++){
        if(p[i]!=i){
            int a=q[i];
            ans.push_back({i,n-1}); swap(q[p[i]],q[p[n-1]]); swap(p[i],p[n-1]);
            ans.push_back({n-1,a}); swap(q[p[n-1]],q[p[a]]); swap(p[n-1],p[a]);
            ans.push_back({i,n-1}); swap(q[p[i]],q[p[n-1]]); swap(p[i],p[n-1]);
        }
    }
    for(int i=n/2;i<n;i++){
        if(p[i]!=i){
            int a=q[i];
            ans.push_back({i,0}); swap(q[p[i]],q[p[0]]); swap(p[i],p[0]);
            ans.push_back({0,a}); swap(q[p[0]],q[p[a]]); swap(p[0],p[a]);
            ans.push_back({i,0}); swap(q[p[i]],q[p[0]]); swap(p[i],p[0]);
        }
    }
    printf("%lld\n",(int)ans.size());
    for(auto[a,b]:ans)printf("%lld %lld\n",a+1,b+1);
}