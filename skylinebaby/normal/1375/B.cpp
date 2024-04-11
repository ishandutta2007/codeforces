#include <bits/stdc++.h>  
#define ll long long int
#define llu unsigned long long int
#define endl '\n'
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define pb push_back
#define SZ(x) ((int)x.size())
using namespace std;
 
 
ll mod = 1e9 + 7;
ll power(ll x, ll n, ll mod) {
  ll res = 1;
  x %= mod;
  while (n) {
	if (n & 1)
	  res = (res * x) % mod;
	x = (x * x) % mod;
	n >>= 1;
  }
  return res;
}
 
 
 
 
 
 
 
void solve(){
    int n,m;
    cin>>n>>m;
    
    int a[n][m];
    
    
    loop(i,0,n){
        loop(j,0,m){
            cin>>a[i][j];
        }
    }
    
     loop(i,0,n){
        loop(j,0,m){
            
            if(a[i][j]==0)
            continue;
            else if(a[i][j]>4){
                cout<<"NO"<<endl;
                return;               
            }
            else{
                
                
                    if(((i==j&&i==0)||(i==n-1&&j==m-1))||((i==0&&j==m-1)||(j==0&&i==n-1))){
                        if(a[i][j]>=3){
                            cout<<"NO"<<endl;
                            return;
                        }
                    }
                    else if(i==0||i==n-1||j==0||j==m-1){
                    if(a[i][j]>=4){
                    cout<<"NO"<<endl;
                    return;
                    }
                    }  
                
            }
            
        }
     }
     
     cout<<"YES"<<endl;
     loop(i,0,n){
        loop(j,0,m){
            
            if(((i==j&&i==0)||(i==n-1&&j==m-1))||((i==0&&j==m-1)||(j==0&&i==n-1))){
                cout<<2<<" ";
            }else if(i==0||i==n-1||j==0||j==m-1){
                cout<<3<<" ";
            }else if(a[i][j]<=4)
            cout<<4<<" ";
            else
            cout<<a[i][j]<<" ";
        }cout<<endl;
     }
     
     
    
    
    
    
    
    
}
 
 
int main()
{
 
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    loop(i,0,t)
    solve();
 
    return 0;
}