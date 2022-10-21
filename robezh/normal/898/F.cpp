#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int mods[4] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 21, (int)1e9 + 33};
const int N = (int)1e6 + 500;

int n;
string s;
int p = 10;
ll pw[4][N];



struct hs {
    ll val[4];

    hs() { fill(val, val + 4, 0); }

    hs(ll a, ll b, ll c, ll d) {
        val[0] = a, val[1] = b, val[2] = c, val[3] = d;
    }

    bool operator<(const hs &other) const {
        for (int i = 0; i < 4; i++) if (val[i] != other.val[i]) return val[i] < other.val[i];
        return false;
    }

    bool operator==(const hs &other) const {
        for (int i = 0; i < 4; i++) if (val[i] != other.val[i]) return false;
        return true;
    }

    hs operator + (const hs &other) const{
        hs res;
        for(int i = 0; i < 4; i++) res.val[i] = ( val[i] + other.val[i]) % mods[i];
        return res;
    }

    hs operator - (const hs &other) const{
        hs res;
        for(int i = 0; i < 4; i++) res.val[i] = (val[i] - other.val[i] + mods[i]) % mods[i];
        return res;
    }


    void add(int x, int pwi){
        for(int i = 0; i < 4; i++) val[i] = (val[i] + x * pw[i][pwi]) % mods[i];
    }

    void up_pow(int pwi){
        for(int i = 0; i < 4; i++) val[i] = (val[i] * pw[i][pwi]) % mods[i];
    }
};

hs ssum[N];

hs get(int a, int b){
    hs res = ssum[a] - ssum[b+1];
//    for(int i = 0; i < 4; i++){
//        cout << res.val[i] << " ";
//    }
//    cout << endl;
    res.up_pow(n-b);
//    for(int i = 0; i < 4; i++){
//        cout << res.val[i] << " ";
//    }
//    cout << endl;

    return res;
}

bool valid(int a, int b){
    return a == b || s[a] != '0';
}

string sub(int a, int b){
    return s.substr(a, b - a + 1);
}

string solve(int l2, int l3){
    if (valid(1, l2-1) && valid(l2, l3 - 1) && valid(l3, n))
        if (get(1, l2-1) + get(l2, l3 - 1) == get(l3, n)) {
            return sub(1, l2-1) + "+" + sub(l2, l3-1) + "=" + sub(l3, n);
        }
    return "-1";
}

int main(){
    getline(cin, s);
    n = s.length();
    for(int t = 0; t < 4; t++){
        pw[t][n] = 1;
        for(int i = n - 1; i >= 0; i--) pw[t][i] = pw[t][i+1] * p % mods[t];
    }
    s = " " + s;
    for(int i = n; i >= 1; i--){
        ssum[i] = ssum[i+1];
        ssum[i].add(s[i] - '0', i);
    }

//    cout << solve(2, 3);


    for(int slack = 0; slack < 2; slack ++){
        for(int len = n / 3; len <= (n - slack - 1) / 2; len++){
            string res = solve(len+1, n-len-slack+1);
            if(res != "-1"){
                cout << res << endl;
                return 0;
            }
            res = solve(n-len*2-slack+1, n-len-slack+1);
            if(res != "-1"){
                cout << res << endl;
                return 0;
            }
        }
    }
}