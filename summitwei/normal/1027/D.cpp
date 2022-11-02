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

int costs[MAX_N];
int nxt[MAX_N];

int curCycle;
int status[MAX_N];

int findMin(int curr, int last){
    if(curr == last){
        return costs[curr];
    } else{
        return min(costs[curr], findMin(nxt[curr], last));
    }
}

int fillStatus(int curr){
    //cout << "status of " << curr << " is " << status[curr] << "\n";
    if(status[curr] != 0 && status[curr] != curCycle){
        return 0;
    }
    if(status[curr] == curCycle){
        return findMin(nxt[curr], curr);
    }

    status[curr] = curCycle;
    return fillStatus(nxt[curr]);
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> costs[i];
    }
    for(int i=1; i<=n; i++){
        cin >> nxt[i];
    }

    int sum = 0;
    for(int i=1; i<=n; i++){
        if(status[i] == 0){
            curCycle++;
            sum += fillStatus(i);
        }
    }

    cout << sum << "\n";

    return 0;
}