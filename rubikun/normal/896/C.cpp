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
const int mod=1000000007,MAX=105;
const ll INF=1LL<<60;

ll rui(ll a,ll b,ll mo){
    a%=mo;
    ll ans=1;
    while(b>0){
        if(b&1) ans=ans*a%mo;
        a=a*a%mo;
        b/=2;
    }
    return ans;
}

ll N,M,seed,vmax,ret;

ll rnd(){
    ret=seed;
    seed=(seed*7+13)%mod;
    return ret;
}

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>M>>seed>>vmax;
    
    vector<ll> A(N);
    ll sum=0;
    
    set<pair<int,ll>> SE;
    
    for(int i=0;i<N;i++){
        A[i]=rnd()%vmax+1;
        SE.insert(mp(i,A[i]));
    }
    
    for(int i=0;i<M;i++){
        int op=rnd()%4+1,l=rnd()%N+1,r=rnd()%N+1,x=-1,y=-1;
        if(l>r) swap(l,r);
        if(op==3){
            x=rnd()%(r-l+1)+1;
        }else{
            x=rnd()%vmax+1;
        }
        
        if(op==4){
            y=rnd()%vmax+1;
        }
        
        //cout<<op<<" "<<l<<" "<<r<<" "<<x<<" "<<y<<endl;
        
        l--;
        if(op==1){
            {
                auto it=SE.lower_bound(mp(r,-1));
                if(it==SE.end()||(*it).fi!=r){
                    it--;
                    if(r<N) SE.insert(mp(r,(*it).se));
                }
            }
            
            {
                vector<pair<int,ll>> tasu;
                auto it=SE.lower_bound(mp(l,-1));
                if(it==SE.end()||(*it).fi>l){
                    it--;
                    ll a=(*it).se+x;
                    SE.insert(mp(l,a));
                    it=SE.lower_bound(mp(l,a+1));
                }
                while(it!=SE.end()&&(*it).fi<r){
                    tasu.push_back(*it);
                    it=SE.erase(it);
                }
                
                for(auto a:tasu) SE.insert(mp(a.fi,a.se+x));
            }
        }
        if(op==2){
            {
                auto it=SE.lower_bound(mp(r,-1));
                if(it==SE.end()||(*it).fi!=r){
                    it--;
                    if(r<N) SE.insert(mp(r,(*it).se));
                }
            }
            
            {
                auto it=SE.lower_bound(mp(l,-1));
                while(it!=SE.end()&&(*it).fi<r){
                    it=SE.erase(it);
                }
            }
            
            SE.insert(mp(l,x));
        }
        if(op==3){
            vector<pair<ll,int>> S;
            auto it=SE.lower_bound(mp(l,-1));
            if(it==SE.end()||(*it).fi>l){
                int s;
                if(it==SE.end()) s=min((ll)r,N);
                else s=min(r,(*it).fi);
                it--;
                S.push_back(mp((*it).se,s-l));
                it++;
            }
            while(it!=SE.end()&&(*it).fi<r){
                int s=(*it).fi;
                ll t=(*it).se;
                it++;
                if(it==SE.end()||(*it).fi>=r){
                    it--;
                    S.push_back(mp((*it).se,r-(*it).fi));
                    break;
                }else{
                    S.push_back(mp(t,(*it).fi-s));
                }
            }
            
            sort(all(S));
            int sum=0;
            for(auto a:S){
                sum+=a.se;
                if(sum>=x){
                    cout<<a.fi<<"\n";
                    break;
                }
            }
        }
        if(op==4){
            vector<pair<ll,int>> S;
            auto it=SE.lower_bound(mp(l,-1));
            if(it==SE.end()||(*it).fi>l){
                int s;
                if(it==SE.end()) s=min((ll)r,N);
                else s=min(r,(*it).fi);
                it--;
                S.push_back(mp((*it).se,s-l));
                it++;
            }
            while(it!=SE.end()&&(*it).fi<r){
                int s=(*it).fi;
                ll t=(*it).se;
                it++;
                if(it==SE.end()||(*it).fi>=r){
                    it--;
                    S.push_back(mp((*it).se,r-(*it).fi));
                    break;
                }else{
                    S.push_back(mp(t,(*it).fi-s));
                }
            }
            
            ll sum=0;
            
            for(auto a:S){
                sum+=rui(a.fi,x,y)*a.se%y;
                sum%=y;
                
                //cout<<a.fi<<" "<<a.se<<endl;
            }
            
            cout<<sum<<"\n";
        }
        
    }
    
}