#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef long long ll;
const long long MOD = 1000000007;
long long fact[100005];

int N, v;
vector<pair<int, int> > pa;

ll inv(ll a, ll b = MOD - 2) {
    if (b== 0) return 1;
    if (b%2 == 0) return inv((a*a)%MOD, b/2);
    return (a*inv((a*a)%MOD, b/2)) % MOD;
}

ll comb(ll a, ll b) {
    if(a < 0 || b < 0 || a < b) return 0;
    return (((fact[a]*inv(fact[b])) % MOD) * inv(fact[a-b])) % MOD;
}

ll coun(int l, int r) {
    ll w = 1;
    //cout << l << " " << r << " " << w << endl;
    for(int i=1; i<pa.size(); i++){
        if(pa[i].second > r){
            w = (w * comb(pa[i].first - pa[i-1].first - 1, pa[i].second-r-1)) % MOD;
            r = pa[i].second;
            l = r - pa[i].first;
        }
        else if(pa[i].second < l){
            w = (w * comb(pa[i].first - pa[i-1].first - 1, l-pa[i].second-1)) % MOD;
            l = pa[i].second;
            r = l + pa[i].first;
        }
        else return 0;
        //cout << l << " " << r << " " << w << endl;
    }
    return w;
}

int main(){
    fact[0] = 1;
    for(int i=1; i<=100000; i++)
        fact[i] = (fact[i-1]*i)%MOD;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> v;
        if(v) pa.push_back(make_pair(v-1, i));
    }
    pa.push_back(make_pair(N, -1));
    pa.push_back(make_pair(N+1, N));
    sort(pa.begin(), pa.end());
    
    if(pa.size() == 2){
        cout << inv(2, N-1) << endl;
        return 0;
    }
    ll w;
    if(pa[0].first == 0){
        w = coun(pa[0].second, pa[0].second);
        
    }
    else{
        int leftk = pa[0].first;
        for(int i=0; i<pa.size(); i++) if (pa[i].second < pa[0].second){
            leftk = min(leftk, pa[0].second - pa[i].second - 1);
        }
        int rightk = pa[0].first;
        for(int i=0; i<pa.size(); i++) if (pa[i].second > pa[0].second){
            rightk = min(rightk, pa[i].second - pa[0].second - 1);
        }
        ll lefts = 0;
        for(int j = 1; j <= leftk; j++) lefts=(lefts+comb(pa[0].first-1, j-1))%MOD;
        ll rights = 0;
        for(int j = 1; j <= rightk; j++) rights=(rights+comb(pa[0].first-1,j-1))%MOD;
        //cout << "L " << lefts << " R " << rights << endl;
        w = (lefts * coun(pa[0].second - pa[0].first, pa[0].second)) % MOD;
        ll w2 = (rights * coun(pa[0].second, pa[0].second + pa[0].first)) % MOD;
        w = (w + w2) % MOD;
    }
    cout << w << endl;
    return 0;
}