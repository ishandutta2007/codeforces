#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
string p[MN];

bool fc(int ut, char c){
    FOR(i, 0, ut){
        F0R(j, p[i].length()){
            if(p[i][j] == c) return true;
        }
    }

    return false;
}

int gb(int ut, char c){
    if(ut == -1) return 0;

    int mb = 0, cb = 0;
    F0R(i, p[ut].length()){
        if(p[ut][i] == c){
            cb++;
            mb = max(mb, cb);
        } else{
            cb = 0;
        }
    }
    int eb = cb;
    int sb = 0;
    while(sb != p[ut].length() && p[ut][sb] == c) sb++;

    if(mb == p[ut].length()){
        int bst = gb(ut-1, c);
        return bst+(bst+1)*mb;
    } else if(p[ut][0] == p[ut][p[ut].length()-1] == c){
        int res;
        if(fc(ut-1, c)){
            res = 1+sb+eb;
        } else{
            res = max(sb, eb);
        }
        return max(res, mb);
    } else if(mb != 0){
        int res = mb;
        if(p[ut][0] == c && fc(ut-1, c)){
            res = max(res, sb+1);
        }
        if(p[ut][p[ut].length()-1] == c && fc(ut-1, c)){
            res = max(res, eb+1);
        }

        return res;
    } else{
        if(fc(ut-1, c)) return 1;
        else return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        cin >> p[i];
    }

    int mb = 0, cb = 0;
    F0R(i, p[n-1].length()){
        if(i == 0 || p[n-1][i] == p[n-1][i-1]){
            cb++;
            mb = max(mb, cb);
        } else{
            cb = 1;
        }
    }
    int eb = cb;
    int sb = 1;
    while(sb != p[n-1].length() && p[n-1][sb] == p[n-1][sb-1]) sb++;

    if(mb == p[n-1].length()){
        int bst = gb(n-2, p[n-1][0]);
        cout << bst+(bst+1)*mb << "\n";
    } else if(p[n-1][0] == p[n-1][p[n-1].length()-1]){
        int res;
        if(fc(n-2, p[n-1][0])){
            res = 1+sb+eb;
        } else{
            res = max(sb, eb);
        }
        cout << max(res, mb) << "\n";
    } else{
        int res = mb;
        if(fc(n-2, p[n-1][0])){
            res = max(res, sb+1);
        }
        if(fc(n-2, p[n-1][p[n-1].length()-1])){
            res = max(res, eb+1);
        }

        cout << res << "\n";
    }

    return 0;
}