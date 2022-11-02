#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 3000005

int tree[MAX_N];
int N;

void update(int node, int a, int b, int l, int r){
    if(a > r || b < l || a > b) return;

    if(a == b){
        tree[node]++;
        return;
    }

    update(node*2, a, (a+b)/2, l, r);
    update(node*2+1, (a+b)/2+1, b, l, r);

    tree[node] = tree[node*2]+tree[node*2+1];
}

int query(int node, int a, int b, int l, int r){
    if(a > r || b < l || a > b) return 0;

    if(l <= a && b <= r){
        return tree[node];
    }

    int q1 = query(node*2, a, (a+b)/2, l, r);
    int q2 = query(node*2+1, (a+b)/2+1, b, l, r);

    return q1 + q2;
}

int findQuery(int v, int k){
    int l = v-k+1;
    int r = v+k-1;

    int sum = 0;

    if(l > 0){
        sum += query(1, 1, N, l, v-1);
    } else{
        sum += (query(1, 1, N, l+N, N) + query(1, 1, N, 1, v-1));
    }

    if(r <= N){
        sum += query(1, 1, N, v+1, r);
    } else{
        sum += (query(1, 1, N, 1, r-N) + query(1, 1, N, v+1, N));
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> N >> k;

    if(k > N/2){
        k = N-k;
    }

    ll currNum = 1;
    int currNode = 1;
    for(int i=1; i<=N; i++){
        update(1, 1, N, currNode, currNode);

        /*for(int j=1; j<=2*N; j++){
            cout << tree[j] << " ";
        }
        cout << "\n";*/

        ll newAmt = (ll)findQuery(currNode, k);

        currNum += (newAmt+1);
        currNode = (currNode+k-1)%N+1;
        cout << currNum << " ";
    }

    return 0;
}