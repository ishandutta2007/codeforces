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
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
int n, m;
int a[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    F0R(i, n){
        cin >> a[i];
    }
    
    int l = -1;
    int r = m;
    while(l+1 < r){
        bool ok = true;

        int mid = (l+r)/2;

        int cur;
        if(a[0]+mid >= m) cur = 0;
        else cur = a[0];
        FOR(i, 1, n-1){
            if(a[i]+mid >= cur+m){
                continue;
            } else{
                if(a[i] < cur){
                    /*ok = false;
                    break;*/
                    if(a[i]+mid >= cur){
                        continue;
                    } else{
                        ok = false;
                        break;
                    }
                } else{
                    cur = a[i];
                }
            }
        }

        if(ok){
            r = mid;
        } else{
            l = mid;
        }
    }

    cout << r << "\n";
    
    return 0;
}