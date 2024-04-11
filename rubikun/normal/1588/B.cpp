#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=1000000007,MAX=300005,INF=1<<30;

ll ask(int l,int r){
    cout<<"? "<<l<<" "<<r<<endl;
    ll res;cin>>res;
    return res;
}

void ans(int a,int b,int c){
    cout<<"! "<<a<<" "<<b<<" "<<c<<endl;
}

ll solve(ll x){
    ll l=0,r=INF;
    while(r-l>1){
        ll m=(l+r)/2;
        if(m*(m-1)/2>=x) r=m;
        else l=m;
    }
    return r;
}

int main(){
    
    /*
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
     */
    
    int Q;cin>>Q;
    while(Q--){
        int N;cin>>N;
        ll X=ask(1,N);
        int l=1,r=N+1;
        while(r-l>1){
            int m=(l+r)/2;
            ll a=ask(l,m-1);
            if(a==X){
                r=m;
                continue;
            }
            if(a==0){
                l=m-1;
                continue;
            }
            ll b=ask(m,r-1);
            if(a+b==X){
                ll aa=solve(a),bb=solve(b);
                ans(m-aa,m,m+bb-1);
                break;
            }
            ll aa=solve(a);
            if(aa*(aa-1)/2==a&&m-aa>=l){
                ll c=ask(m-aa,m-1);
                if(c==a){
                    ll left=1,right=r-m;
                    while(right-left>1){
                        ll mid=(left+right)/2;
                        ll d=ask(m,m+mid-1);
                        if(d==mid*(mid-1)/2) left=mid;
                        else right=mid;
                    }
                    ll rem=b-left*(left-1)/2;
                    ll d=solve(rem);
                    ans(m-aa,m+left,m+left+d-1);
                    break;
                }else{
                    ll bb=solve(b);
                    ll c=ask(m,m+bb-1);
                    ll left=1,right=m-l;
                    while(right-left>1){
                        ll mid=(left+right)/2;
                        ll d=ask(m-mid,m-1);
                        if(d==mid*(mid-1)/2) left=mid;
                        else right=mid;
                    }
                    ll rem=a-left*(left-1)/2;
                    ll d=solve(rem);
                    ans(m-left-d,m-left,m+bb-1);
                    break;
                }
            }else{
                ll bb=solve(b);
                ll c=ask(m,m+bb-1);
                ll left=1,right=m-l;
                while(right-left>1){
                    ll mid=(left+right)/2;
                    ll d=ask(m-mid,m-1);
                    if(d==mid*(mid-1)/2) left=mid;
                    else right=mid;
                }
                ll rem=a-left*(left-1)/2;
                ll d=solve(rem);
                ans(m-left-d,m-left,m+bb-1);
                break;
            }
        }
    }
}