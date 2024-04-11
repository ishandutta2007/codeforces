#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000000000005LL
#define MOD 1000000007LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int q;
int n; ll k;
string s; string t1, t2, t3;
ll len[MN];
char get(int n, ll k){
    if(k >= len[n]) return '.';
    if(n == 0) return s[k];
    if(k < t1.length()) return t1[k];
    if(k < t1.length()+len[n-1]) return get(n-1, k-t1.length());
    if(k < t1.length()+len[n-1]+t2.length()) return t2[k-t1.length()-len[n-1]];
    if(k < t1.length()+len[n-1]+t2.length()+len[n-1]) return get(n-1, k-t1.length()-len[n-1]-t2.length());
    if(k < t1.length()+len[n-1]+t2.length()+len[n-1]+t3.length()) return t3[k-t1.length()-len[n-1]-t2.length()-len[n-1]];
    return '.';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    s = "What are you doing at the end of the world? Are you busy? Will you save us?";
    t1 = "What are you doing while sending \"";
    t2 = "\"? Are you busy? Will you send \"";
    t3 = "\"?";

    len[0] = s.length();
    FOR(i, 1, MN-2){
        len[i] = len[i-1]*2+t1.length()+t2.length()+t3.length();
        if(len[i] > INF) len[i] = INF;
    }

    cin >> q;
    F0R(_, q){
        cin >> n >> k; --k;
        cout << get(n, k);
    }
    
    return 0;
}