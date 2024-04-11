#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 10000000000000000L
#define SMALLINF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005

int tree[3*MAX_N];
int N;

ll arr[MAX_N];
pll inOrder[MAX_N];
pll revOrder[MAX_N];
int toOrder[MAX_N];

int maxLen[MAX_N];

int path[MAX_N];

void update(int node, int a, int b, int l, int r, int val){
    if(a > r || b < l || a > b) return;

    if(a == b){
        tree[node] = max(tree[node], val); //LIKE THIS SO THAT SOMETHING SMALLER DOESN'T REDUCE THIS VALUE
        return;
    }

    update(node*2, a, (a+b)/2, l, r, val);
    update(node*2+1, (a+b)/2+1, b, l, r, val);

    tree[node] = max(tree[node*2], tree[node*2+1]);
}

int query(int node, int a, int b, int l, int r){
    if(a > r || b < l || a > b) return -SMALLINF;

    if(l <= a && b <= r){
        return tree[node];
    }

    int q1 = query(node*2, a, (a+b)/2, l, r);
    int q2 = query(node*2+1, (a+b)/2+1, b, l, r);

    return max(q1, q2);
}

int getQuery(ll h, ll d){
    //cout << "doing " << h << " " << d << "\n";

    int left = lower_bound(revOrder, revOrder+N+1, make_pair(h-d, 1LL*INF), greater<pll>())-revOrder;
    int right = lower_bound(inOrder, inOrder+N+1, make_pair(h+d, 1LL*0))-inOrder;

    left = N+1-left;

    //cout << "left side is " << left << " and right is " << right << "\n";

    int maxAmt = 0;
    if(left != 0){
        maxAmt = max(maxAmt, query(1, 1, N, 1, left));
    }
    if(right != N+1){
        maxAmt = max(maxAmt, query(1, 1, N, right, N));
    }

    return maxAmt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll d;
    cin >> N >> d;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        inOrder[i+1] = {arr[i], i};
    }

    inOrder[0] = make_pair(1LL*-INF, 1LL*-INF);
    memcpy(revOrder, inOrder, sizeof inOrder);
    revOrder[0] = make_pair(1LL*INF, 1LL*INF);

    sort(revOrder, revOrder+N+1, greater<pll>());
    sort(inOrder, inOrder+N+1);
    for(int i=1; i<=N; i++){
        //toOrder[inOrder[i].second] = i;
        toOrder[inOrder[i].second] = i;
    }

    /*for(int i=0; i<=N; i++){
        cout << revOrder[i].first << " " << revOrder[i].second << "\n";
    }*/

    /*for(int i=0; i<=N; i++){
        cout << inOrder[i].first << " " << inOrder[i].second << "\n";
    }
    for(int i=0; i<N; i++){
        cout << toOrder[i] << " ";
    }
    cout << "\n";*/


    int maxPath = 0;
    int loc;
    for(int i=0; i<N; i++){
        int prevMax = getQuery(arr[i], d);

        maxLen[i] = prevMax+1;
        
        if(prevMax+1 > maxPath){
            loc = i;
            maxPath = max(maxPath, prevMax+1);
        }
        update(1, 1, N, toOrder[i], toOrder[i], prevMax+1);
    }

    int curLen = maxPath;
    int curOn = loc;
    path[maxPath] = loc+1;
    for(int i=loc-1; i>=0; i--){
        if(maxLen[i] >= curLen-1 && ((arr[curOn]-arr[i])>=d || (arr[curOn]-arr[i]) <= -d)){
            //cout << "we found one :O at " << i << "\n";
            curOn = i;
            curLen--;
            path[curLen] = i+1;
        }
    }

    cout << maxPath << "\n";
    for(int i=1; i<=maxPath; i++){
        cout << path[i] << " ";
    }

    /*cout << "\n";
    for(int i=0; i<N; i++){
        cout << maxLen[i] << " ";
    }*/

    return 0;
}