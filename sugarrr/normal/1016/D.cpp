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
#include<set>
#include<map>
#include<bitset>

using namespace std;
typedef long long ll;
#define i_7 1000000007
#define i_5 1000000005

ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=1000000000000;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}


//////////////////////////////////////


int main(){
    int n,m;cin>>n>>m;
    int a[n];rep(i,0,n-1)cin>>a[i];
    int b[m];rep(i,0,m-1)cin>>b[i];
    int ans[n][m];memset(ans,0,sizeof(ans));
    rep(i,0,30){
        vector<int>s,t;
        rep(j,0,n-1){
            if(((a[j]>>i)&1)==1){
                s.push_back(j);
            }
        }
        rep(j,0,m-1){
            if(((b[j]>>i)&1)==1){
                t.push_back(j);
            }
        }
        if(s.size()%2!=t.size()%2){
            cout<<"NO"<<endl;
            return 0;
        }
        int spos=0,tpos=0;
        while(!s.empty()&&!t.empty()&&spos<=s.size()-1&&tpos<=t.size()-1){
            ans[s[spos]][t[tpos]]+=1<<i;
            spos++;
            tpos++;
        }
        while(!s.empty()&&spos<=s.size()-1){
            ans[s[spos]][0]+=1<<i;
            spos++;
        }
        while(!t.empty()&&tpos<=t.size()-1){
            ans[0][t[tpos]]+=1<<i;
            tpos++;
        }
        
    }
    cout<<"YES"<<endl;
    rep(i,0,n-1){
        rep(j,0,m-1){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    
    return 0;
}