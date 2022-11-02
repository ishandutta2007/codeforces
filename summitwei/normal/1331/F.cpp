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
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int ok[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s = "H He Li Be B C N O F Ne Na Mg Al Si P S Cl Ar K Ca Sc Ti V Cr Mn Fe Co Ni Cu Zn Ga Ge As Se Br Kr Rb Sr Y Zr Nb Mo Tc Ru Rh Pd Ag Cd In Sn Sb Te I Xe Cs Ba La Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu Hf Ta W Re Os Ir Pt Au Hg Tl Pb Bi Po At Rn Fr Ra Ac Th Pa U Np Pu Am Cm Bk Cf Es Fm Md No Lr Rf Db Sg Bh Hs Mt Ds Rg Cn Nh Fl Mc Lv Ts Og";
    string t;
    cin >> t;
    F0R(i, t.length()){
        /*string aah = t.substr(i, 2);
        aah[1] = aah[1]-'A'+'a';
        if(s.find(aah) != string::npos){
            //cout << "YES\n";
            cout << aah << " ";
            //return 0;
        }*/
        if(s.find(t.substr(i, 1)+" ") != string::npos){
            //cout << "found single " << i << "\n";
            if(i == 0 || ok[i-1]) ok[i] = true;
        }
        if(i != 0){
            string aah = t.substr(i-1, 2);
            aah[1] = aah[1]-'A'+'a';
            if(s.find(aah) != string::npos){
                //cout << "found dbl " << i << "\n";
                if(i == 1 || ok[i-2]) ok[i] = true;
            }
        }
    }
    if(ok[t.length()-1]) cout << "YES\n";
    else cout << "NO\n";
    /*string aah = t.substr(0, 2);
    aah[1] = aah[1]-'A'+'a';
    if(s.find(aah) != string::npos){
        cout << "YES\n";
    } else cout << "NO\n";*/
    return 0;
}