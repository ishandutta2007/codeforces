#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 200005
string s, t;
vpii strA, strB; //REVERSE ORDER
bool swp;

int calc(int a, int b, int sm){
    if(a < b) swap(a, b);
    if(sm){
        return max(a-1, b);
    } else{
        return a-1;
    }
}

pii lstA(){ return strA[strA.size()-1]; }
pii lstB(){ return strB[strB.size()-1]; }
void opt(int x, int y){
    if(swp) cout << y << " " << x << "\n";
    else cout << x << " " << y << "\n";
}
void insA(pii toIns){
    if(lstA().f == toIns.f){
        strA[strA.size()-1].s += toIns.s;
    } else{
        strA.pb(toIns);
    }
}
void insB(pii toIns){
    if(lstB().f == toIns.f){
        strB[strB.size()-1].s += toIns.s;
    } else{
        strB.pb(toIns);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> t;
    int stk = 0;
    int pv = s[s.size()-1]-'a';
    RFOR(i, s.size()-1, 0){
        if(s[i]-'a' != pv){
            strA.pb({pv, stk});
            pv = s[i]-'a';
            stk = 1;
        } else{
            stk++;
        }
    }
    strA.pb({pv, stk});
    stk = 0; pv = t[t.size()-1]-'a';
    RFOR(i, t.size()-1, 0){
        if(t[i]-'a' != pv){
            strB.pb({pv, stk});
            pv = t[i]-'a';
            stk = 1;
        } else{
            stk++;
        }
    }
    strB.pb({pv, stk});

    /*for(auto u : strA) cout << u.f << " " << u.s << "\n";
    cout << "\n";
    for(auto u : strB) cout << u.f << " " << u.s << "\n";
    cout << "\n";*/
    if(strA.size() < strB.size()){ swap(strA, strB); swp = !swp; }
    int n = strA.size(); int m = strB.size();

    //do nothing
    int op1 = calc(n, m, strA[n-1].f==strB[m-1].f);

    //swap a and empty
    int op2 = INF;
    int loc2 = -1;
    FOR(i, 1, n-1){
        int nn = n-i;
        int nm = m+i-1+(strA[n-i].f!=strB[m-1].f);
        bool nsm = (strA[n-i-1].f==strA[n-1].f);
        int res = calc(nn, nm, nsm)+1;
        //cout << i << " " << nn << " " << nm << " " << nsm << " yields " << res << "\n";
        if(res < op2){
            op2 = res;
            loc2 = i;
        }
    }

    //swap a and first of b
    int op3 = INF;
    int loc3 = -1;
    FOR(i, 1, n-1){
        int nn = n-i+(strA[n-1-i].f!=strB[m-1].f);
        int nm = m+i-1-1+(m==1 || strA[n-i].f!=strB[m-2].f);
        bool nsm = strA[n-1].f==strB[m-1].f;
        int res = calc(nn, nm, nsm)+1;
        //cout << i << " " << nn << " " << nm << " " << nsm << " yields " << res << "\n";
        if(res < op3){
            op3 = res;
            loc3 = i;
        }
    }

    if(op1 <= op2 && op1 <= op3){
        //cout << "no first\n";
        cout << op1 << "\n";
    } else if(op2 <= op1 && op2 <= op3){
        //cout << "swap " << loc2 << " w/ none\n";
        cout << op2 << "\n";
        int sm = 0;
        RFOR(i, n-1, n-loc2){
            sm += strA[i].s;
        }
        opt(sm, 0);
        FOR(i, n-loc2, n-1){
            insB(strA[i]);
        }
        F0R(_, loc2) strA.pop_back();
    } else{
        //cout << "swap " << loc3 << " w/ last\n";
        cout << op3 << "\n";
        int sm = 0;
        RFOR(i, n-1, n-loc3){
            sm += strA[i].s;
        }
        opt(sm, strB[m-1].s);
        pii tmp = strB[m-1];
        strB.pop_back();
        FOR(i, n-loc3, n-1){
            insB(strA[i]);
        }
        F0R(_, loc3) strA.pop_back();
        insA(tmp);
    }

    if(strA.size() < strB.size()){ swp = !swp; swap(strA, strB); }
    
    if(lstA().f == lstB().f){
        opt(lstA().s, 0);
        insB(lstA());
        strA.pop_back();
    }

    if(strA.size() < strB.size()){ swp = !swp; swap(strA, strB); }

    while(strA.size() != 1){
        opt(lstA().s, lstB().s);

        pii tmp = lstA();
        strA.pop_back();
        
        insA(lstB());
        strB.pop_back();

        insB(tmp);
    }

    return 0;
}