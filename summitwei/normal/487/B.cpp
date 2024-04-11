#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)

int N, s, l;
int a[MAX_N];
int maxt[3*MAX_N];
int mint[3*MAX_N];
int leftmostRange[MAX_N];
int dp[MAX_N];
int dpt[3*MAX_N];

void update(int node, int a, int b, int i, int j, int val, int type){ //type 0 = max, 1 = min, 2 = dp
    if(a > b || a > j || b < i) return;

    if(a == b){
        if(type == 0){
            maxt[node] = val;
        } else if(type == 1){
            mint[node] = val;
        } else{
            dpt[node] = val;
        }
        return;
    }

    update(node*2, a, (a+b)/2, i, j, val, type);
    update(node*2+1, (a+b)/2+1, b, i, j, val, type);

    if(type == 0){
        maxt[node] = max(maxt[node*2], maxt[node*2+1]);
    } else if(type == 1){
        mint[node] = min(mint[node*2], mint[node*2+1]);
    } else{
        dpt[node] = min(dpt[node*2], dpt[node*2+1]);
    }
}

int query(int node, int a, int b, int i, int j, int type){
    if(a > b || a > j || b < i){
        if(type == 0) return -INF;
        else return INF;
    }

    if(a >= i && b <= j){
        if(type == 0){
            return maxt[node];
        } else if(type == 1){
            return mint[node];
        } else{
            return dpt[node];
        }
    }

    int q1 = query(node*2, a, (a+b)/2, i, j, type);
    int q2 = query(node*2+1, 1+(a+b)/2, b, i, j, type);
    
    if(type == 0){
        return max(q1, q2);
    } else{
        return min(q1, q2);
    }
}

void getLefts(){
    FOR(i, 1, N){
        int left = max(0, leftmostRange[i-1]-1), right = i;
        while(left+1 < right){
            /*if(left > i-l+1){ //this one already has nothing so just stop
                break;
            }*/

            int mid = (left+right)/2;
            int maxv = query(1, 1, N, mid, i, 0);
            int minv = query(1, 1, N, mid, i, 1);

            if(maxv-minv <= s){
                right = mid;
            } else{
                left = mid;
            }
        }

        leftmostRange[i] = right;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> s >> l;
    FOR(i, 1, N){
        cin >> a[i];
        update(1, 1, N, i, i, a[i], 0);
        update(1, 1, N, i, i, a[i], 1);
    }

    getLefts();

    /*FOR(i, 1, N){
        cout << leftmostRange[i] << " ";
    }*/

    FOR(i, 1, N){
        int left = leftmostRange[i]-1;
        int right = i-l;


        dp[i] = query(1, 1, N, max(1, left), right, 2) + 1;
        if(left == 0 && left <= right){
            dp[i] = min(dp[i], 1);
        }
        update(1, 1, N, i, i, dp[i], 2);
    }

    int ans = dp[N];
    if(ans > 100000){
        cout << "-1\n";
    } else{
        cout << ans << "\n";
    }

    return 0;
}