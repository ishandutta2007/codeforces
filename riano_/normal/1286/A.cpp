#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;
#define double long double

const ll mod = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N; cin >> N;
    ll a[N+2]; a[0] = -1; a[N+1] = -1;
    bool app[N+1];
    rep(i,N+1) app[i] = false;
    rep(i,N){
        cin >> a[i+1]; app[a[i+1]] = true;
    }
    ll ans = 0;
    vector<ll> od,ev,ab;
    vector<Pr> ed;
    ll l = 0; ll cnt = 0;
    rep(i,N){
        if(a[i+1]!=0) continue;
        cnt++;
        if(a[i]!=0) l = a[i];
        if(a[i+2]!=0){
            ll r = a[i+2];
            if(l==-1&&r==-1){
                if(N==1){
                    cout << 0 << endl; return 0;
                }
                cout << 1 << endl; return 0;
            }
            if(l*r<0){
                if((l*r)*(-1)%2==0){
                    ed.push_back(make_pair(cnt,0));
                }
                else ed.push_back(make_pair(cnt,1));
            }
            else{
                if(abs(l-r)%2==0){
                    if(l%2==0) ev.push_back(cnt);
                    else od.push_back(cnt);
                }
                else ab.push_back(cnt);
            }
            cnt = 0;
        }
    }
    ll en = 0,on = 0;
    rep(i,N){
        if(!app[i+1]){
            if((i+1)%2==0) en++;
            else on++;
        }
    }
    rep(i,N-1){
        if(a[i+1]*a[i+2]==0) continue;
        if((a[i+2]+a[i+1])%2==1) ans++;
    }
    sort(od.begin(),od.end()); sort(ev.begin(),ev.end());
    int M1 = od.size(); int M2 = ev.size();
    ans += ab.size();

    int L = ed.size();
    ll cost = 2e9;
    rep(i,(1<<L)){
        ll eu = 0,ou = 0;
        ll cn = 0;
        rep(j,L){
            if(i&(1<<j)){
                auto[s,p] = ed[j];
                if(p==0) eu += s;
                else ou += s;
            }
            else cn++;
        }
        if(eu>en||ou>on) continue;
        rep(j,M1){
            if(ou+od[j]>on){
                cn += 2*(M1-j); break;
            }
            else ou += od[j];
        }
        rep(j,M2){
            if(eu+ev[j]>en){
                cn += 2*(M2-j); break;
            }
            else eu += ev[j];
        }
        cost = min(cost,cn);
    }

    cout << ans+cost << endl;
}