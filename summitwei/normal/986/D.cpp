#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (ll i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (ll i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)
 
typedef complex<double> cd;
const double PI = acos(-1);
 
#define MN 1500005
#define BS 1000

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vll mult(vll const& a, vll const& b){
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size()) n <<= 1;
    fa.resize(n);
    fb.resize(n);
 
    fft(fa, false);
    fft(fb, false);
    F0R(i, n){
        fa[i] *= fb[i];
    }
    fft(fa, true);
    vll res(n);
    F0R(i, n){
        res[i] = round(fa[i].real());
    }
 
    int car = 0;
    F0R(i, n){
        res[i] += car;
        car = res[i]/BS;
        res[i] %= BS;
    }
    
    int lst = n;
    while(lst != 0 && res[lst-1] == 0) --lst;
    res.resize(lst);
    /*n = 1;
    while(n <= lst) n <<= 1;
    //cout << "lst is " << lst << "\n";
    res.resize(n);*/

    return res;
}

vll scMult(vll const& a, int b){
    int n = 1;
    while(n < a.size() + 1) n <<= 1;
 
    vll res(n);
    int car = 0;
    F0R(i, n){
        if(i < a.size()) res[i] = a[i]*b+car;
        else res[i] = car;
        car = res[i]/BS;
        res[i] %= BS;
    }
    
    int lst = n;
    while(lst != 0 && res[lst-1] == 0) --lst;
    res.resize(lst);
    /*n = 1;
    while(n <= lst) n <<= 1;
    //cout << "lst is " << lst << "\n";
    res.resize(n);*/
 
    return res;
}

bool comp(vll const& a, vll const& b){ //true if <
    //if(a.size() != b.size()) return a.size() < b.size();
    if(a.size() > b.size()){
        RFOR(i, a.size()-1, b.size()){
            if(a[i] != 0) return false;
        }
    } else if(b.size() > a.size()){
        RFOR(i, b.size()-1, a.size()){
            if(b[i] != 0) return true;
        }
    }
    int mn = min(a.size(), b.size());
    RFOR(i, mn-1, 0){
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

vll reee[30]; //3^(2^i)
vll res, fin;
 
bool bad;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    string s;
    cin >> s;
    if(s[0] == '6') bad = true;
    //if(bad) cout << s.size() << "\n";
    
    if(s == "1"){
        cout << "1\n";
        return 0;
    }
    fin.resize((s.length()+2)/3);
    F0R(i, s.length()){
        int loc = (s.length()-1-i)/3;
        fin[loc] = fin[loc] * 10 + s[i]-'0';
    }
    /*for(auto u : fin) cout << u << " ";
    cout << "\n";*/
 
    int sz = (s.length()*log(10)/log(3))-6;
    sz = max(sz, 0);
 
    reee[0].pb(3);
    FOR(i, 1, 21){
        reee[i] = mult(reee[i-1], reee[i-1]);
    }
    
    //if(bad){cout << "finished mults\n";}
 
    /*for(auto u : reee[5]) cout << u << " ";
    cout << "\n";*/
 
    //cout << "doing " << sz << "\n";
    int sz2 = sz;
 
    res.pb(1);
 
    //largest power of 3 smaller than this guy
    FOR(i, 0, 21){
        //cout << "doing " << i << "\n";
        if(sz & (1<<i)){
            res = mult(res, reee[i]);
            sz2 -= (1<<i);
        }
        /*if(bad && i == 11){
            cout << "finished 11\n";
            return 0;
        }*/
    }
    /*if(bad){
        cout << "hmm finished exp\n";
        return 0;
    }*/
    assert(sz2 == 0);
 
    /*for(auto u : res) cout << u << " ";
    cout << "\n";*/
 
    int ans = INF;
 
    F0R(i, 3){ //# of 2s
        int cur = sz*3+i*2;
        vll bleh = scMult(res, 1<<i);
        /*for(auto u : bleh) cout << u << " ";
        cout << "\n";*/
        int k=0;
        while(comp(bleh, fin)){
            //cout << "hi\n";
            bleh = scMult(bleh, 3);
            cur += 3;
            ++k;
            //for(auto u : bleh) cout << u << " ";
            //cout << "\n";
            assert(k <= 7);
        }
        ans = min(ans, cur);
    }
 
    cout << ans << "\n";
 
    return 0;
}