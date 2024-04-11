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

int main(){
    int n, k;
    cin >> n >> k;
    
    string inp;
    cin >> inp;

    string ans;
    ans.resize(k);

    int numUsed = 0;
    int numLeft = 0;
    for(int i=0; i<n; i++){
        if(numUsed == k) break;

        if(numLeft < k/2 && inp[i] == '('){
            ans[numUsed] = '(';
            numUsed++;
            numLeft++;
        } else if(inp[i] == ')'){
            ans[numUsed] = ')';
            numUsed++;
        }
    }

    cout << ans << "\n";

    return 0;
}