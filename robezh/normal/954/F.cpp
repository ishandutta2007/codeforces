#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<ll, Pi> P;

const ll mod = (ll)1e9 + 7;

struct mat{
    ll a[3][3];
    mat(){
        for(int i = 0; i < 3; i++)for(int j = 0; j < 3; j++) a[i][j] = 1;
        a[0][2] = a[2][0] = 0;
    }

    mat(int p){
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    a[i][j] = (i == j ? p : 0);
    }

    mat operator *(const mat& t) const{
        mat res = mat(0);
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3; k++)
                    res.a[i][j] = ( res.a[i][j] + a[i][k] * t.a[k][j]) % mod;

        return res;
    }
};

mat m = mat();
int n;
ll co;
int ba[10050];
ll bl[10050], br[10050];
vector<P> bpoint;
int oc[4];

mat fast_exp(ll k){
    if(k == 0) return mat(1);
    if(k == 1) return m;
    mat half = fast_exp(k/2);
    return (k%2 == 1 ? half * half * m : half * half);
    
};

void d1(){m.a[0][0] = m.a[0][1] = 0;}
void r1(){m.a[0][0] = m.a[0][1] = 1;}
void d2(){m.a[1][0] = m.a[1][1] = m.a[1][2] = 0;}
void r2(){m.a[1][0] = m.a[1][1] = m.a[1][2] = 1;}
void d3(){m.a[2][1] = m.a[2][2] = 0;}
void r3(){m.a[2][1] = m.a[2][2] = 1;}

int main(){
    scanf("%d%I64d", &n, &co);
    for(int i = 0; i < n; i++){
        scanf("%d%I64d%I64d", &ba[i], &bl[i], &br[i]);
        br[i] ++;
        bpoint.push_back(P(bl[i], Pi(ba[i], 0)));
        bpoint.push_back(P(br[i], Pi(ba[i], 1)));
    }
    fill(oc, oc+4, 0);
    ll pre = 2;
    mat res = mat(1);

    sort(bpoint.begin(), bpoint.end());
    for(P bp : bpoint){
        //cout << bp.first << " " << bp.second.first << " " << bp.second.second << endl;
        ll now = bp.first;
        int na = bp.second.first;
        int sta = bp.second.second;

        res = fast_exp(now - pre) * res;
        if(sta == 0){if(na == 1) oc[1]++; else if(na == 2)oc[2] ++; else oc[3]++;}
        else{if(na == 1) oc[1]--; else if(na == 2) oc[2]--; else oc[3]--;}

        if(oc[1] > 0) d1(); else r1();
        if(oc[2] > 0) d2(); else r2();
        if(oc[3] > 0) d3(); else r3();
        pre = now;
    }
    res = fast_exp(co - pre + 1) * res;

    ll ans = res.a[1][1];

    cout << ans;

}