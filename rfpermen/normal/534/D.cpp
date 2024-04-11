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
int n,x,ans[MAX],cur;
vector<int> v[MAX];
int main(){
    //cout<<fixed<<setprecision(2);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    rep(i,1,n){
        cin>>x;
        v[x].pb(i);
    }
    rep(i,1,n){
		while(cur>2&&v[cur].empty())cur-=3;
        if(v[cur].size()==0){
            cout<<"Impossible"<<endl;
            return 0;
        }
        ans[i]=v[cur].back();
        v[cur].pob();
        cur++;
    }
    cout<<"Possible"<<endl;
    rep(i,1,n){
        cout<<ans[i];
        if(i==n)cout<<endl;
        else cout<<" ";
    }
    return 0;
}