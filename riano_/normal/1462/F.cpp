#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;
#define double long double

const ll mod = 1000000007;


//compression 
class compress {
public:
    map<ll,ll> label;
    vector<ll> inverse;
    set<ll> num;
    bool ready;
    compress(int a){
        num.insert(0);
        label[0] = 0;
        inverse.push_back(0);
        ready = false;
    }

    //x
    void add(ll x){
        num.insert(x); ready = false;
    }

    //sort
    void labeling(void){
        inverse.clear();
        int k = 0;
        for(ll x:num){
            inverse.push_back(x);
            label[x] = k; k++;
        }
    }

    //x
    ll lab(ll x){
        if(!ready){
            labeling(); ready = true;
        }
        return label[x];
    }

    //i
    ll inv(ll i){
        if(!ready){
            labeling(); ready = true;
        }
        return inverse[i];
    }

    //size
    ll size(void){
        if(!ready){
            labeling(); ready = true;
        }
        return inverse.size();
    }

};


//segment tree
//1-indexed all
class segtree {
public:
    ll n;
    vector<ll> A;
    segtree(ll k){
        n = 1;
        while(n<k){ n *= 2; }
        A=vector<ll>(2*n,0);
    }

    //a[i]x
    void add(ll i,ll x){
        int index = n-1+i;
        A[index] += x;
        while(index>1){
            index /= 2;
            A[index] = A[2*index]+A[2*index+1];
        }
    }

    //a[i]
    void replace(ll i,ll x){
        int index = n-1+i;
        A[index] = x;
        while(index>1){
            index /= 2;
            A[index] = A[2*index]+A[2*index+1];
        }
    }

    //a[i]+a[i+1]++a[j]
    ll sum(ll i,ll j){
        return rangesum(i,j,1,1,n);
    }

    // a,b k c,d(k=1,c=1,d=n)
    ll rangesum(ll a,ll b,ll k,ll c,ll d){
        //
        ll el = 0;
        if(d<a||b<c){
            return el;
        }
        else if(a<=c&&d<=b){
            return A[k];
        }
        else{
            //2
            ll p = rangesum(a,b,k*2,c,(c+d)/2)+rangesum(a,b,k*2+1,(c+d)/2+1,d);
            return p;
        }
    }

};

    
    

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    
    rep(ii,T){
        ll N; cin >> N;
        //main
        compress comp(1); //1
        vector<Pr> seg;
        rep(i,N){
            ll l,r; cin >> l >> r;
            seg.push_back(make_pair(r,l));
            comp.add(l); comp.add(r);
        }
        sort(seg.begin(),seg.end());
        //main
        segtree left(2*N+2),right(2*N+2);
        rep(i,N){
            auto[r,l] = seg[i];
            left.add(comp.lab(l),1);
        }
        ll cr = 0;
        rep(i,N){
            ll cn = 1;
            auto[r,l] = seg[i];
            left.add(comp.lab(l),-1);
            cn += left.sum(1,comp.lab(r));
            cn += right.sum(comp.lab(l),comp.lab(r));
            right.add(comp.lab(r),1);
            cr = max(cr,cn);
        }
        cout << N-cr << endl;
    }
    //cout << ans << endl;
}