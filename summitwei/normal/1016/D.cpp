#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 105

int rows[MAX_N];
int cols[MAX_N];

int main(){
    int n, m;
    cin >> n >> m;

    int rowsComb = 0;
    for(int i=0; i<n; i++){
        cin >> rows[i];
        rowsComb = rowsComb ^ rows[i];
    }

    int colsComb = 0;
    for(int i=0; i<m; i++){
        cin >> cols[i];
        colsComb = colsComb ^ cols[i];
    }

    if(rowsComb != colsComb){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            cout << "0 ";
        }
        cout << rows[i] << "\n";
    }
    for(int j=0; j<m-1; j++){
        cout << cols[j] << " ";
    }
    cout << (rows[n-1] ^ cols[m-1] ^ colsComb) << "\n";

    return 0;
}