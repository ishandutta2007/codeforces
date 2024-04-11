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

const int N=2040;

int n,t,a[N];
vector<int> v;

void op(int x){
   v.pb(x);
   f(i,1,x/2+1)
      swap(a[i],a[x-i+1]);
}

int main(){
   cin>>t;
   while(t--){
      int mv=0;
   cin>>n;
   f(i,1,n+1){
      cin>>a[i];
      if((i&1)!=(a[i]&1)){
         mv=1;
      }
   }
   if(mv==0){
   for(int i=n;i>1;i-=2){
      f(j,1,n+1){
         if(a[j]==i){
            op(j);
            break;
         }
      }
      f(j,2,n+1){
         if(a[j]==i-1){
            op(j-1);
            op(j+1);
            op(3);
            op(i);
            break;
         }
      }
   }
   cout<<v.size()<<endl;
   f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl;
   v.clear();
   }
   else
      cout<<-1<<endl;
   }
}