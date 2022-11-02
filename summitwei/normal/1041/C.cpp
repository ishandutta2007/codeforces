#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 200005

pii times[MAX_N];
int ans[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d;
    cin >> n >> m >> d;
    for(int i=0; i<n; i++){
        cin >> times[i].first;
        times[i].second = i;
    }

    sort(times, times+n);

    int maxDist = 0;
    int minLast = n;
    for(int i=0; i<n; i++){
        int bin = lower_bound(times, times+n, make_pair(times[i].first+d+1, 0))-times;
        if(bin != n){
            int dist = bin-i;
            maxDist = max(maxDist, dist);
        } else{
            if(minLast == n){
                minLast = i;
            }
        }
    }
    //if(maxDist == 0) maxDist = n;
    maxDist = max(maxDist, n-minLast);

    cout << maxDist << "\n";
    for(int i=0; i<n; i++){
        ans[times[i].second] = i%maxDist + 1;
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}