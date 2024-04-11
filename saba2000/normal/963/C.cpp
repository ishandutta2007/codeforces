#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> C[200009];
vector<ll> A;
vector<ll> B;
map<pair<ll,ll>,ll> M;
ll sa[200009],sb[200009];
set<ll> a,b;
main(){
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++){
       ll h,w ,c;
       scanf("%lld%lld%lld",&h,&w,&c);
        M[{h,w}] = c;
        a.insert(h);
        b.insert(w);
    }
    if(a.size() * b.size() > n) {
        cout<<0<<endl;
        return 0;

    }
    set<pair<ll,ll> > pas;
    ll I = 0;
    for(auto i = a.begin(); i !=a.end(); i++)
    A.push_back(*i);
     for (auto j = b.begin(); j != b.end();j++)
        B.push_back(*j);
      n = A.size(); ll m = B.size();
    for(auto i = a.begin(); i !=a.end(); i++,I++) {
    for (auto j = b.begin(); j != b.end();j++)
        C[I].push_back(M[{*i,*j}]);
    }
    //a1 a2 .. an
    ll fl = 1, Fl = 0;
    //b1 b2 .. bm
    ll K = C[0][0];
    vector<ll> G;
    for (ll i = 1; i *i <= K; i++)
        if(K % i) continue;
    else G.push_back(i),G.push_back(K/i);
    for (ll i = 0; i< G.size(); i++){
        sa[0] = G[i];
        sb[0] = K / G[i];
        ll fl = 1;
        for (ll i = 1; i < m; i++)
            if(C[0][i] % sa[0]) fl = 0;
        else sb[i] = C[0][i] / sa[0];
        for (ll i = 1; i < n; i++)
            if(C[i][0] % sb[0]) fl =0;
        else sa[i] = C[i][0] / sb[0];

        if(!fl) continue;
        if(Fl == 0){
            for (ll i =0 ;i < n; i++)
                for(ll j =0; j < m; j++)
                    if(C[i][j] % sa[i] || C[i][j]/sa[i] != sb[j]) fl =0;
            if(fl == 0) Fl = -1;
            else Fl  = 1;
        }
        if(Fl == -1) fl =0;
        if(!fl) continue;
        ll AA = 0, AA1 = 0, BB1  =0, BB = 0;
        for (ll i = 0; i < n; i++)
            {
                AA += sa[i]*A[i];
            }
        for (ll i = 0; i < m; i++)
            BB += sb[i]*B[i];
        pas.insert({AA,BB});
    }
    cout<<pas.size()<<endl;
}