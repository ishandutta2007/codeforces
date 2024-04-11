#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005

pii pairs[MAX_N];

int main(){
    int n, m;
    cin >> n >> m;

    int amt = 0;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(__gcd(i, j) == 1){
                pairs[amt] = {i, j};
                amt++;
            }
            if(amt == m) break;
        }
        if(amt == m) break;
    }

    if(m < n-1 || m > amt){
        cout << "Impossible\n";
    } else{
        cout << "Possible\n";
        for(int i=0; i<m; i++){
            cout << pairs[i].first << " " << pairs[i].second << "\n";
        }
    }

    return 0;
}