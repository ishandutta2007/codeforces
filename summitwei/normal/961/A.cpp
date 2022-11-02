#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
#define MODBASE 1000000007
#define INF 1000000000

int main(){
    int n, m;
    cin >> n >> m;

    vi cols(n, 0);
    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        cols[k-1]++;
    }

    int minCol = INF;
    for(int i=0; i<n; i++){
        minCol = min(minCol, cols[i]);
    }

    cout << minCol;

    return 0;
}