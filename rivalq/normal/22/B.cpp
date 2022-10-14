//https://codeforces.com/contest/22/problem/B
#include<bits/stdc++.h>
#define lop(i,n,a) for(int i=0;i<n;i+=a)
#define rep(i,n,a) for(int i=a;i<n;i++)
#define ll long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl "\n"
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret return 0
#define pi 3.1415926536
#define mod 1000000007
using namespace std;
int solve(){
  int n,m;cin>>n>>m;
  char arr[n][m];
  lop(i,n,1){
      lop(j,m,1)cin>>arr[i][j];
  }
  int p=4;
  for (int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        for(int k=0;k<m;k++){
            for(int l=k;l<m;l++){
                int q=1;
                for(int g=i;g<=j;g++){
                    for(int h=k;h<=l;h++){
                        if(arr[g][h]=='1'){
                            q=0;goto br;
                        }
                    }
                }
                br:
                if(q){
                    p=max(p,2*(j-i+1)+2*(l-k+1));
                }
            }
        }
    }
  }
  cout<<p<<endl;
  
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ll t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}