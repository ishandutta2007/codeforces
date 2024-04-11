#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 10000000000000000LL
#define MOD 1000000007
#define MOD2 998244353
#define BLEH 137
#define BLEH2 147
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); ++i)
#define F0R(i, a) for (int i=0; i<(signed)(a); ++i)
#define RFOR(i, a, b) for (int i=(a); i >= b; --i)

#define MN 1000005
#define AL 26
char s1[MN];
int len;

ll modExp(ll b, ll ex, ll md){
    ll prod = 1;
    while(ex > 0){
        if(ex % 2 == 0){
            b = (b * b) % md;
            ex /= 2;
        } else{
            prod = (prod*b) % md;
            ex--;
        }
    }
    
    return prod;
}

int bad(string s2){
    //it's called bad b/c that's what hashing is
    ll a = 0, b = 0;
    ll a2 = 0, b2 = 0;
    int lst = -1;
    F0R(i, s2.length()){
        char ac = s1[len-1-i];
        a += ac*modExp(BLEH, i, MOD);
        a %= MOD;
        a2 += ac*modExp(BLEH2, i, MOD2);
        a2 %= MOD2;
        char bc = s2[i];
        b = b*BLEH+bc;
        b %= MOD;
        b2 = b2*BLEH2+bc;
        b2 %= MOD2;

        //cout << ac << " " << bc << "\n";
        //cout << a << " " << b << "\n";
        //cout << a2 << " " << b2 << "\n";

        if(a == b && a2 == b2) lst = i;
    }
    return lst;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string cur;
    cin >> cur;
    F0R(i, cur.length()){
        s1[i] = cur[i];
    }
    len=cur.length();

    F0R(_, n-1){
        //cout << "string is " << cur << "\n";
        string news;
        cin >> news;
        int ree = bad(news);
        FOR(i, ree+1, news.length()-1){
            s1[len-ree-1+i] = news[i];
        }
        len = len+news.length()-ree-1;
    }

    F0R(i, len){
        cout << s1[i];
    }

    return 0;
}