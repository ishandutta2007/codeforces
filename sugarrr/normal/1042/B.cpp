#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;/*10^12*/
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
////////////////////////////////////////


int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    
    int n;cin>>n;
    ll a=inf,b=inf,c=inf,ab=inf,bc=inf,ca=inf,abc=inf;
    rep(i,0,n-1){
        int k;string s;cin>>k>>s;
        if(s.size()==3){
            abc=min(abc,k);
        }else if(s.size()==2){
            if(s[0]=='A'||s[1]=='A'){
                if(s[0]=='B'||s[1]=='B'){
                    ab=min(ab,k);
                }else{
                    ca=min(ca,k);
                }
            }else{
                bc=min(bc,k);
            }
        }else{
            if(s[0]=='A'){
                a=min(a,k);
            }else if(s[0]=='B'){
                b=min(b,k);
            }else{
                c=min(c,k);
            }
        }
    }
    ab=min(ab,abc);
    bc=min(bc,abc);
    ca=min(ca,abc);
    a=min(a,ab);
    a=min(a,ca);
    b=min(b,bc);
    b=min(b,ab);
    c=min(c,ca);
    c=min(c,bc);
    
    ll ans=abc;
    ans=min(ans,ab+c);
    ans=min(ans,bc+a);
    ans=min(ans,ca+b);
    ans=min(ans,a+b+c);
    
    
    if(ans>=inf){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    
    return 0;
}