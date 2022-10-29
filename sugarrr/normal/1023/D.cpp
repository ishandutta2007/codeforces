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
    int n,q;cin>>n>>q;
    int a[n];rep(i,0,n-1)cin>>a[i];
    bool fff=true;
    rep(i,0,n-1)if(a[i]!=0)fff=false;
    if(fff){
        cout<<"YES"<<endl;
        rep(i,0,n-1)cout<<q<<" ";
        cout<<endl;
        return 0;
    }
    bool ff=false;
    rep(i,0,n-1)if(a[i]==q)ff=true;
    if(ff){
        int first;
        rep(i,0,n-1){
            if(a[i]!=0){first=a[i];break;}
        }
        bool fla=true;
        rep(i,0,n-1){
            if(i==0&&a[i]==0&&fla){
                a[i]=first;
                fla=false;
            }else if(a[i]==0&&i<=n-2){
                a[i]=max(a[i-1],a[i+1]);
            }else if(a[i]==0&&i==n-1){
                a[i]=a[i-1];
            }
        }
    }else{
        
        bool fla=true;
        rep(i,0,n-1){
            if(a[i]==0&&fla){
                a[i]=q;
                fla=false;
            }else if(a[i]==0&&i<=n-2){
                a[i]=max(a[i-1],a[i+1]);
            }else if(a[i]==0&&i==n-1){
                a[i]=a[i-1];
            }
        }
    }
    bool fffff=false;
    rep(i,0,n-1){
        if(a[i]==q)fffff=true;
    }
    if(!fffff){
        cout<<"NO"<<endl;
        return 0;
    }
    
    
    
    int b[q+1];memset(b,0,sizeof(b));//02()
    
    priority_queue<int> p;
    
    rep(i,0,n-1){
        if(i==0){
            p.push(a[i]);
        }else{
            if(b[a[i]]==2){
                cout<<"NO"<<endl;
                return 0;
            }else if(a[i]>a[i-1]){
                p.push(a[i]);
            }else if(a[i]==a[i-1]){
            }else{
                while(!p.empty()){
                    int t=p.top();
                    if(t>a[i]){
                        b[t]=2;
                        p.pop();
                    }else{
                        break;
                    }
                }
                
                p.push(a[i]);
            }
        }
    }
    cout<<"YES"<<endl;
    rep(i,0,n-1){
        cout<<a[i]<<" ";
    }
    
    
    return 0;
}