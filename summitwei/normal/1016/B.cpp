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

int n, m, q;
string s, t;

vector<int> startingLocs;

int main(){
    cin >> n >> m >> q;
    cin >> s >> t;

    for(int i=0; i<n-m+1; i++){
        int works = true;
        for(int j=0; j<m; j++){
            if(s[i+j] != t[j]){
                works = false;
                break;
            }
        }

        if(works){
            startingLocs.push_back(i);
        }
    }

    /*for(int i=0; i<startingLocs.size(); i++){
        cout << startingLocs[i] << "\n";
    }*/

    for(int i=0; i<q; i++){
        int cnt = 0;

        int l, r;
        cin >> l >> r;
        l--;
        r--;

        for(int j=0; j<startingLocs.size(); j++){
            if(l<=startingLocs[j] && r>=startingLocs[j]+m-1){
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}