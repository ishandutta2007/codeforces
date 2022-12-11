#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

template<class T>bool chmax(T &a,const T &b){
    if(a>b)return false;
    a=b;
    return true;
}
template<class T>bool chmin(T &a,const T &b){
    if(a<b)return false;
    a=b;
    return true;
}

/*-------------------------------------------*/

int n,p[109],num[2],ans;
vector<int> v1[2],v2[2];

int f(int x,int y){
    rep(i,v2[y].size()){
        if(x>=0)return i*2;
        x+=v2[y][i];
    }
    if(x>=0)return v2[y].size()*2;
    return mod;
}

int main(){
    cin>>n;
    num[0]=n/2;
    num[1]=num[0]+n%2;
    rep(i,n){
        cin>>p[i];
        if(p[i])num[p[i]%2]--;
    }
    int cnt=1;
    rep(i,n){
        if(p[i]==0)cnt++;
        else{
            if(cnt!=1){
                if(i-cnt<0){
                    v1[p[i]%2].push_back(cnt-1);
                    num[p[i]%2]-=cnt-1;
                }
                else if(p[i-cnt]%2==p[i]%2){
                    v2[p[i]%2].push_back(cnt-1);
                    num[p[i]%2]-=cnt-1;
                }
            }
            if(i-cnt>=0&&p[i-cnt]%2!=p[i]%2)ans++;
            cnt=1;
        }
    }
    if(cnt>n){
        cout<<min(n/2,1)<<endl;
        return 0;
    }
    if(cnt!=1){
        v1[p[n-cnt]%2].push_back(cnt-1);
        num[p[n-cnt]%2]-=cnt-1;
    }
    if(num[0]>=0&&num[1]>=0){
        cout<<ans<<endl;
        return 0;
    }
    sort(v2[0].begin(),v2[0].end(),greater<int>());
    sort(v2[1].begin(),v2[1].end(),greater<int>());
    sort(v1[0].begin(),v1[0].end(),greater<int>());
    sort(v1[1].begin(),v1[1].end(),greater<int>());

    int x=1e9,y=0;
    if(num[1]<0)y=1;
    x=ans+f(num[y],y);
    rep(i,v1[y].size()){
        num[y]+=v1[y][i];
        ans++;
        chmin(x,ans+f(num[y],y));
    }
    cout<<x<<endl;
}