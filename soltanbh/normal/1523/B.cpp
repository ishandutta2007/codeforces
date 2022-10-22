#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e6+99;

int n,t,a[N];
vector<pair<int,pair<int,int> >> ans;

void op(int x){
    x++;
    ans.pb(mp(1,mp(x,x+1)));
    ans.pb(mp(2,mp(x,x+1)));
    ans.pb(mp(1,mp(x,x+1)));
}

int main(){
   cin>>t;
   while(t--){
       ans.clear();
       cin>>n;
       f(i,0,n) cin>>a[i];
       for(int i=0;i<n;i+=2)
           op(i),op(i);
       cout<<ans.size()<<endl;
       f(i,0,ans.size())
           cout<<ans[i].F<<" "<<ans[i].S.F<<" "<<ans[i].S.S<<endl;
   }
}