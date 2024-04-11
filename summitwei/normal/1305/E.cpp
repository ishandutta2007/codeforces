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

#define MN 5005
int n, m;

int c2(int x){
    return x*(x-1)/2;
}
int ree(int x){
    return c2((x+1)/2)+c2(x/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int mx = ree(n);
    if(mx < m){
        cout << "-1\n";
        return 0;
    }
    RFOR(i, n, 1){
        //cout << i << " " << ree(i) << "\n";
        if(ree(i) <= m){
            FOR(j, 1, i){
                cout << j << " ";
            }
            if(i == n) return 0;
            int got = i;
            int rest = m-ree(i);
            int j = i+1;
            while(rest != 0){
                int prs;
                if(j%2==0){
                    int fst = (j+2)/2;
                    prs = (i-fst+1);
                } else{
                    int fst = (j+1)/2;
                    prs = (i-fst+1);
                }
                //cout << j << " gets " << prs << "\n";
                if(prs == rest){
                    cout << j << " ";
                    ++got;
                    break;
                } else{
                    ++j;
                }
            }
            FOR(k, got+1, n){
                cout << 20000*k+1 << " ";
            }
            return 0;
        }
    }


    return 0;
}