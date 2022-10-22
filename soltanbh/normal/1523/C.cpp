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

const int N=1009;

int n,t,a[N],mark[N];

int main(){
   cin>>t;
   while(t--){
       cin>>n;
       fill(mark,mark+N,0);
       vector<vector<int> > ans(n+2);
       vector<vector<int> > v(n+2);
       f(i,0,n){
           cin>>a[i];
       }
       ans[0].pb(1);
       v[1].pb(0);
       cout<<1<<endl;
       f(i,1,n){
           if(a[i]==1) ans[i]=ans[i-1],ans[i].pb(1);
           else{
               int last,x=a[i]-1;
               while(v[x].size() && mark[v[x][v[x].size()-1]])
                   v[x].pop_back();
               if(v[x].size()==0) return 0;
               last=v[x][v[x].size()-1];
               v[x].pop_back();
               f(j,last,i) mark[j]=1;
               ans[i]=ans[last];
               ans[i][ans[i].size()-1]++;
           }
           v[a[i]].pb(i);
           f(j,0,ans[i].size()){
               if(j) cout<<'.';
               cout<<ans[i][j];
           }
           cout<<endl;
       }
   }
}