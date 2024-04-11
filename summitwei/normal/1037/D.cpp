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

vi adj[MAX_N];
queue<int> bfs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    bfs.push(1);
    int first;
    cin >> first;
    if(first != 1){
        cout << "No\n";
        return 0;
    }

    while(!bfs.empty()){
        int top = bfs.front();
        int children = top==1 ? adj[top].size() : adj[top].size()-1;
        //cout << "processing " << top << " which has " << children << " children\n";
        bfs.pop();
        for(int i=0; i<children; i++){
            int ch;
            cin >> ch;
            if(!binary_search(adj[top].begin(), adj[top].end(), ch)){
                //cout << "Node " << ch << " is out of order\n";
                cout << "No\n";
                return 0;
            }
            bfs.push(ch);
        }
    }

    cout << "Yes\n";
    return 0;
}