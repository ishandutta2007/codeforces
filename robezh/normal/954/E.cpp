#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

typedef pair<ld, ld> Pd;
const int MAXN = 200050;
const ld EPS = 1e-6;

bool iszero(ld k){
    return abs(k) < EPS;
}

int n;
ld T;
ld Tot = 0;
ld amountnow = 0;
ld a[MAXN], t[MAXN];
vector<Pd> wat;

bool cmp(Pd p1, Pd p2){
    return p1.second > p2.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> T;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> t[i];
    for(int i = 0; i < n; i++){
        wat.push_back(Pd(a[i], t[i]-T));
        Tot += (a[i]) * (t[i]-T);
        amountnow += a[i];
    }
    if(iszero(Tot)){cout << fixed << setprecision(15) << amountnow; return 0;}
    if(Tot < 0){
        for(int i = 0; i < wat.size(); i++){
            wat[i].second = -wat[i].second;
        }
        Tot = -Tot;
    }

    sort(wat.begin(), wat.end(), cmp);
    //for(Pd p : wat){cout << p.first << " " << p.second << endl;}
    for(int i = 0; i < wat.size(); i++) {

        ld ai = wat[i].first, ti = wat[i].second;
        //if(ti == 0) return !printf("0.00000000");
        if (Tot - ai * ti >= 0) {
            Tot -= (ai) * (ti);
            amountnow -= ai;
            //cout << "1. amount now = " << amountnow << " ai ="  << ai << endl;
            if (iszero(Tot)) {
                cout << fixed << setprecision(15) << amountnow;
                return 0;
            }
        } else {
            ld lft = Tot / ti;
            amountnow -= lft;
            //cout << "2. amount now = " << amountnow << " lft = " << lft << endl;
            cout << fixed << setprecision(15) << amountnow;
            return 0;
        }
    }
}