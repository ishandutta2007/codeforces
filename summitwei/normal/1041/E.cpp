#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_PER 200005
#define MAX_N 1005

int edges[MAX_N];
int order[MAX_N];
bool used[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x, y;
        
        cin >> x >> y;
        if(x > y) swap(x, y);

        if(x == n || y != n){
            cout << "NO\n";
            return 0;
        }

        edges[i] = x;
        used[x] = true;
    }

    sort(edges, edges+n-1);
    
    /*for(int i=0; i<n-1; i++){
        cout << edges[i] << " ";
    }*/

    for(int i=0; i<n-1; i++){
        if(edges[i] < i+1){
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    int notUsed = n-1;
    order[0] = n;
    int prev = edges[n-2];
    //cout << prev << "\n";
    int curCh = 1;
    for(int i=n-3; i>=0; i--){
        if(edges[i] != prev){
            order[curCh] = prev;
            prev = edges[i];
            curCh++;
        } else{
            while(used[notUsed]) notUsed--;
            order[curCh] = notUsed;
            notUsed--;

            curCh++;
        }

        /*for(int j=0; j<n; j++){
            cout << order[j] << " ";
        }
        cout << "\n";*/
    }
    order[curCh] = prev;

    /*for(int i=0; i<n; i++){
        cout << order[i] << "\n";
    }*/
    for(int i=0; i<n-1; i++){
        cout << order[i] << " " << order[i+1] << "\n";
    }

    return 0;
}