#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9;
const ll IINF=1e18;

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n; cin >> n;
    struct seg{
        int l,r,y;
        seg(int l,int r,int y):l(l),r(r),y(y){}
        const bool operator<(const seg &rhs){
            return y>rhs.y;
        }
    };
    vector<seg> S;
    for (int i=0;i<n;++i){
        int l,r,y; cin >> l >> r >> y;
        S.emplace_back(l,r,y);
    }
    sort(S.begin(),S.end());
    vector<pair<pair<int,int>,pair<int,int>>> ng;
    for (int i=0;i<n;++i){
        for (int j=i+1;j<n;++j){
            if (S[i].y==S[j].y) continue;
            int d=S[j].l-S[i].r,u=S[j].r-S[i].l,diff=S[i].y-S[j].y;
            int g_d=gcd(abs(d),diff),g_u=gcd(abs(u),diff);
            ng.push_back({{d/g_d,diff/g_d},{u/g_u,diff/g_u}});
        }
    }
    if (ng.empty()){
        int m=INF,M=-INF;
        for (int i=0;i<n;++i){
            m=min(m,S[i].l);
            M=max(M,S[i].r);
        }
        cout << M-m << '\n';
        return 0;
    }
    vector<pair<int,int>> comp;
    for (auto p:ng){
        comp.emplace_back(p.first);
        comp.emplace_back(p.second);
    }
    auto f=[](pair<int,int> a,pair<int,int> b){return (ll)a.first*b.second<(ll)a.second*b.first;};
    sort(comp.begin(),comp.end(),f);
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    int MAX=comp.size();
    vector<int> imos(MAX,0);
    for (auto p:ng){
        int L=lower_bound(comp.begin(),comp.end(),p.first,f)-comp.begin();
        int R=lower_bound(comp.begin(),comp.end(),p.second,f)-comp.begin();
        ++imos[L+1]; --imos[R];
    }
    for (int i=0;i<MAX-1;++i) imos[i+1]+=imos[i];
    double ans=1e15;
    for (int i=0;i<MAX;++i){
        if (!imos[i]){
            auto p=comp[i];
            double m=IINF,M=-IINF;
            for (int j=0;j<n;++j){
                m=min(m,S[j].l+(double)p.first*S[j].y/p.second);
                M=max(M,S[j].r+(double)p.first*S[j].y/p.second);
            }
            ans=min(ans,M-m);
        }
    }
    cout << ans << '\n';
}