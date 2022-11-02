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
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 500005
int n, m, k, s;
int a[MN];
int b[MN];

int cnt[MN];
int rbd[MN];

int stat[MN]; //0 = idk, 1 = yes, -1 = no
int app[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> m >> k >> n >> s;
    FOR(i, 1, m){
        cin >> a[i];
    }
    FOR(i, 1, s){
        int x;
        //cin >> b[i];
        cin >> x;
        b[x]++;
    }
    int rb = 0;
    int sat = 0;
    FOR(i, 1, m){
        while(rb <= m && sat < s){
            rb++;

            int c = a[rb];
            if(b[c] > cnt[c]){
                sat++;
            }
            cnt[c]++;
        }
        rbd[i] = max(rb, i+k-1);
        int c = a[i];
        if(b[c] >= cnt[c]) sat--;
        cnt[c]--;
    }

    int dc = 0;

    FOR(i, 1, m){
        //cout << rbd[i] << " ";
        if(rbd[i] == m+1) break;

        int bef = (i-1)/k;
        int aft = (m-rbd[i])/k;
        if(bef+aft+1 >= n){
            //this is good
            //cout << "good at " << i << " w/ rbd of " << rbd[i] << "\n";
            
            FOR(j, i, rbd[i]){
                int c = a[j];
                if(b[c] > app[c]){
                    stat[j] = 1;
                    //cout << "using " << j << "\n";
                }
                app[c]++;
            }
            int added = s;
            FOR(j, i, rbd[i]){
                if(added < k && stat[j] == 0){
                    added++;
                    stat[j] = 1;
                    //cout << j << " included, added is now " << added << "\n";
                } else if(added == k && stat[j] == 0){
                    stat[j] = -1;
                    //cout << j << " bad\n";
                    dc++;
                }
            }

            int td = (i-1)%k;
            if(bef >= n){
                td += (bef+1-n)*k;
            }
            FOR(i, 1, td){
                stat[i] = -1;
                dc++;
            }

            cout << dc << "\n";
            FOR(i, 1, m){
                if(stat[i] == -1) cout << i << " ";
            }

            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}