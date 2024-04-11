#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 200005

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;
    int numSwaps = 0;
    int prevSwap = -INF;
    for(int i=0; i<n-1; i++){
        if((a.substr(i, 2) == "10" && b.substr(i, 2) == "01") || (a.substr(i, 2) == "01" && b.substr(i, 2) == "10")){
            if(prevSwap != i-1){
                numSwaps++;
                prevSwap = i;
            }
        }
    }

    int difs = 0;
    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            difs++;
        }
    }

    cout << difs-numSwaps << "\n";

    return 0;
}