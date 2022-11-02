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
#define MAX_N 300005
#define fi first
#define se second

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

ll tree[2][MAX_N*4];

void update(int node, int a, int b, int i, int j, ll val, int type){
    if(a > b || a > j || b < i || i > j) return;

    if(a == b){
        tree[type][node] += val;
        return;
    }

    update(node*2, a, (a+b)/2, i, j, val, type);
    update(node*2+1, (a+b)/2+1, b, i, j, val, type);

    tree[type][node] = tree[type][node*2] + tree[type][node*2+1];
}

ll query(int node, int a, int b, int i, int j, int type){
    if(a > b || a > j || b < i || i > j){
        return 0;
    }

    if(a >= i && b <= j){
        return tree[type][node];
    }

    ll q1 = query(node*2, a, (a+b)/2, i, j, type);
    ll q2 = query(node*2+1, 1+(a+b)/2, b, i, j, type);
    
    return q1 + q2;
}

struct Person{
    ll p1;
    ll p2;
    int ind;
};

Person ppl[MAX_N];
ll pts[MAX_N];
int N, M;

bool comp(Person a, Person b){
    //if a should be doing the first problem, put a before b
    ll aFirst = a.p1+b.p2;
    ll bFirst = b.p1+a.p2;
    
    return aFirst <= bFirst;
}

ll getPts(int a, int b){
    ll aFirst = ppl[a].p1+ppl[b].p2;
    ll bFirst = ppl[b].p1+ppl[a].p2;

    return min(aFirst, bFirst);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    F0R(i, N){
        cin >> ppl[i].p1 >> ppl[i].p2;
        ppl[i].ind = i;
    }

    F0R(i, M){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ll lost = getPts(u, v);

        pts[u] -= lost;
        pts[v] -= lost;
    }

    /*F0R(i, N){
        cout << "person " << i << " lost " << pts[i] << " pts\n";
    }*/
    
    sort(ppl, ppl+N, comp);
    
    F0R(i, N){
        update(1, 1, N, i+1, i+1, ppl[i].p1, 0);
        update(1, 1, N, i+1, i+1, ppl[i].p2, 1);
        //cout << ppl[i].ind << " ";
    }
    //cout << "\n";

    F0R(i, N){
        ll do1 = N-i-1;
        ll do2 = i;

        ll himPts = ppl[i].p1*do1 + ppl[i].p2*do2;
        ll p1Pts = query(1, 1, N, 1, i, 0);
        ll p2Pts = query(1, 1, N, i+2, N, 1);

        pts[ppl[i].ind] += (himPts + p1Pts + p2Pts);
        //cout << "for person " << ppl[i].ind << ": contributes " << himPts << " and got " << p1Pts + p2Pts << " pts\n";

        //pts[ppl[i].ind] += ppl[i].p1*do1 + ppl[i].p2*do2;
    }

    F0R(i, N){
        cout << pts[i] << " ";
    }
    
    return 0;
}