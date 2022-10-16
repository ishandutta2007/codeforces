#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i,n,N) for(int i=(int)n;i<=(int)N;i++)
#define rap(i,n,N) for(int i=(int)n;i>=(int)N;i--)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define fi first
#define se second
#define pii pair<int,int> 
#define pll pair<ll,ll>
const int MAX=200005;
const int MOD=1000000000 + 7;
const int nr[]={1,-1,0,0,1,1,-1,-1};
const int nc[]={0,0,1,-1,1,-1,1,-1};
ll n,sum,x[MAX],ans[MAX],a,mn,a2,y;
int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a;
    rep(i,1,n)cin>>x[i], sum+=x[i];
    mn=n;
    y=a;
    a-=mn-1;
    //cout<<a<<" "<<a2<<endl;
    rep(i,1,n){
        a2=sum-x[i];
        a2=y-a2;
        //cout<<"ini a2 "<<a2<<endl;
        if(x[i]>a)ans[i]=x[i]-a;
        //cout<<x[i]-a<<endl;
        if(a2>1)ans[i]+=a2-1;

    }
    rep(i,1,n){
        cout<<ans[i];
        if(i!=n)cout<<" ";
        else cout<<endl;
    }
    return 0;
}