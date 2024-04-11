


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
typedef long long ll;
int mod(ll a){return a%1000000007;};

typedef pair<ll,pair<ll,ll>> i_i_i;


int main(){
    ll  n,m,r,k;cin>>n>>m>>r>>k;
    ll a[n+1],b[m+1];
    ll alast,blast;
    if(r<=(n+1)/2){
        for(int i=1;i<=r-1;i++){
            a[i]=2;
        }
        a[r]=n-2*r+2;
        alast=r;
    }else{
        for(int i=1;i<=n-r;i++){
            a[i]=2;
        }
        a[n-r+1]=2*r-n;
        alast=n-r+1;
    }
    if(r<=(m+1)/2){
        for(int i=1;i<=r-1;i++){
            b[i]=2;
        }
        b[r]=m-2*r+2;
        blast=r;
    }else{
        for(int i=1;i<=m-r;i++){
            b[i]=2;
        }
        b[m-r+1]=2*r-m;
        blast=m-r+1;
    }
    vector<i_i_i> v;
    i_i_i xx;
    xx.first=(ll)alast*blast;
    xx.second.first=alast;
    xx.second.second=blast;
    v.push_back(xx);
    ll count=0;
    vector<pair<ll,ll> >map;
    ll ans=0;
    pair<ll,ll> vv;
    vv.first=alast;vv.second=blast;
    map.push_back(vv);
    while(count<k){
        ll max=0;
        pair<ll,ll>maxab;
        int maxi=0;
        int i=0;
        for(i=0;i<v.size();i++){
            if(max<v[i].first)max=v[i].first,maxab.first=v[i].second.first,maxab.second=v[i].second.second,maxi=i;
        }
        if(count+a[maxab.first]*b[maxab.second]<=k){
            count=count+a[maxab.first]*b[maxab.second];
            ans+=a[maxab.first]*b[maxab.second]*max;
        }else{
            ans+=(k-count)*max;
            count=k;
        }
      /*  map[maxab.first][maxab.second]=true;*/
        bool flag=true;
        for(int i=0;i<map.size();i++){
            if(map[i].first==maxab.first-1&&map[i].second==maxab.second){
                flag=false;break;
            }
        }
        if(maxab.first>1)if(flag==true){
            xx.first=(maxab.first-1)*maxab.second;
            xx.second.first=maxab.first-1;
            xx.second.second=maxab.second;
            v.push_back(xx);
            vv.first=maxab.first-1;
            vv.second=maxab.second;
            map.push_back(vv);
        }flag=true;
        for(int i=0;i<map.size();i++){
            if(map[i].first==maxab.first&&map[i].second==maxab.second-1){
                flag=false;break;
            }
        }
        if(maxab.second>1)if(flag==true){
            xx.first=(maxab.first)*(maxab.second-1);
            xx.second.first=maxab.first;
            xx.second.second=maxab.second-1;
            v.push_back(xx);
            vv.first=maxab.first;
            vv.second=maxab.second-1;
            map.push_back(vv);
        }
        v.erase(v.begin()+maxi);
    }
    ll warizan=(ll)(n-r+1)*(m-r+1);
    double aaaaa;
    aaaaa=(double)ans/warizan;
    printf("%0.12lf",aaaaa);
    return 0;
}