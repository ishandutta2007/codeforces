#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 200005

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;

        int first = -1, last;
        for(int j=0; j<m; j++){
            if(s[j] == 'B'){
                if(first == -1) first = j;
                last = j;
            }
        }

        if(first != -1){
            int side = last-first+1;
            int amtAdd = (side-1)/2;

            cout << i+amtAdd+1 << " " << first+amtAdd+1 << "\n";
            return 0;
        }
    }

    return 0;
}