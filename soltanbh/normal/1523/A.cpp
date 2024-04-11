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

int n,t,m;
string s;

int main(){
   cin>>t;
   while(t--){
       cin>>n>>m>>s;
       f(i,0,n){
           if(s[i]=='0' && (i==0 || s[i-1]=='1')){
               int j=i;
               while(j<n && s[j]=='0')
                   j++;
               if(i==0 && j==n){
                   f(k,0,n) cout<<0;
                   break;
               }
               if(i==0 || j==n){
                   j=j-i;
                   if(i==0){
                       f(k,0,j-m) cout<<0;
                       f(k,0,min(j,m)) cout<<1;
                   }
                   else{
                       f(k,0,min(j,m)) cout<<1;
                       f(k,0,j-m) cout<<0;
                   }
               }
               else{
                   j=j-i;
               int s=min(j/2,m);
              // cout<<endl<<s<<endl;
               f(k,0,s) cout<<1;
               f(k,0,j-s*2) cout<<0;
               f(k,0,s) cout<<1;
              // cout<<endl;
               }
           }
           else if( s[i]=='1') cout<<1;
       }
       cout<<endl;
   }
}