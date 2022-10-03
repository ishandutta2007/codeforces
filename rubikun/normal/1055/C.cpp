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
const int mod=1000000007,MAX=2005,INF=1<<30;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

ll solve(ll la,ll ra,ll ta,ll lb,ll rb,ll tb){
    if(ta>tb){
        swap(la,lb);
        swap(ra,rb);
        swap(ta,tb);
    }
    
    if(gcd(ta,tb)==1){
        return min(ra-la+1,rb-lb+1);
    }else{
        if(ta==tb){
            return max(0LL,min(ra,rb)-max(la,lb)+1);
        }else{
            ll g=gcd(ta,tb);
            if(la<=lb){
                ll x=(lb-la)/g;
                la+=x*g;
                ra+=x*g;
                la%=tb;
                ra%=tb;
                if(la>ra) ra+=tb;
                ll ans=0;
                
                chmax(ans,min(ra,rb)-max(la,lb)+1);
                
                la+=g;
                ra+=g;
                //la%=tb;
                //ra%=tb;
                if(la>ra) ra+=tb;
                
                chmax(ans,min(ra,rb)-max(la,lb)+1);
                
                return ans;
            }else{
                ll x=(la-lb)/g;
                la-=x*g;
                ra-=x*g;
                la%=tb;
                ra%=tb;
                if(la<0) la+=tb;
                if(ra<0) ra+=tb;
                if(la>ra) ra+=tb;
                ll ans=0;
                
                chmax(ans,min(ra,rb)-max(la,lb)+1);
                
                la-=g;
                ra-=g;
                //la%=tb;
                //ra%=tb;
                //if(la<0) la+=tb;
                //if(ra<0) ra+=tb;
                if(la>ra) ra+=tb;
                
                chmax(ans,min(ra,rb)-max(la,lb)+1);
                
                return ans;
            }
        }
    }
}

ll solve2(ll la,ll ra,ll ta,ll lb,ll rb,ll tb){
    vector<int> A(200,1);
    for(int i=0;i<200;i++){
        if(!(la<=i%ta&&i%ta<=ra)) A[i]=0;
        if(!(lb<=i%tb&&i%tb<=rb)) A[i]=0;
    }
    
    //for(int i=0;i<20;i++) cout<<i<<" "<<A[i]<<endl;
    int ans=0;
    
    for(int i=0;i<200;i++){
        if(A[i]==0) continue;
        int j=i;
        while(j<200&&A[j]) j++;
        chmax(ans,j-i);
        i=j-1;
    }
    
    return ans;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll la,ra,ta,lb,rb,tb;cin>>la>>ra>>ta>>lb>>rb>>tb;
    
    cout<<solve(la,ra,ta,lb,rb,tb)<<endl;
    
    return 0;
    
    for(ta=2;ta<=10;ta++){
        for(tb=2;tb<=10;tb++){
            for(la=0;la<ta;la++){
                for(ra=la;ra<ta;ra++){
                    for(lb=0;lb<tb;lb++){
                        for(rb=lb;rb<tb;rb++){
                            if(ra-la==ta-1||rb-lb==tb-1) continue;
                            
                            ll res=solve(la,ra,ta,lb,rb,tb),res2=solve2(la,ra,ta,lb,rb,tb);
                            if(res!=res2){
                                cout<<la<<" "<<ra<<" "<<ta<<" "<<lb<<" "<<rb<<" "<<tb<<endl;
                                cout<<res<<" "<<res2<<endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if(ta>tb){
        swap(la,lb);
        swap(ra,rb);
        swap(ta,tb);
    }
    
    if(gcd(ta,tb)==1){
        cout<<min(ra-la+1,rb-lb+1)<<endl;
    }else{
        if(ta==tb){
            cout<<max(0LL,min(ra,rb)-max(la,lb)+1)<<endl;
        }else{
            ll g=gcd(ta,tb);
            if(la<=lb){
                ll x=(lb-la)/g;
                la+=x*g;
                ra+=x*g;
                la%=tb;
                ra%=tb;
                if(la>ra) ra+=tb;
                ll ans=0;
                
                chmax(ans,min(ra,rb)-max(la,lb)+1);
                
                la+=g;
                ra+=g;
                la%=tb;
                ra%=tb;
                if(la>ra) ra+=tb;
                
                chmax(ans,min(ra,rb)-max(la,lb)+1);
                
                cout<<ans<<endl;
            }else{
                ll x=(la-lb)/g;
                la-=x*g;
                ra-=x*g;
                la%=tb;
                ra%=tb;
                if(la<0) la+=tb;
                if(ra<0) ra+=tb;
                if(la>ra) ra+=tb;
                ll ans=0;
                
                chmax(ans,min(ra,rb)-max(la,lb)+1);
                
                la-=g;
                ra-=g;
                la%=tb;
                ra%=tb;
                if(la<0) la+=tb;
                if(ra<0) ra+=tb;
                if(la>ra) ra+=tb;
                
                chmax(ans,min(ra,rb)-max(la,lb)+1);
                
                cout<<ans<<endl;
            }
        }
    }
}