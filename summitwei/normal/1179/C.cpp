#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 0x3f3f3f3f
#define MOD 998244353
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 1000005
#define MS 1000000
int n, m;
int a[MN];
int b[MN];
int ct[MN];
int tree[3*MN];
int lazy[3*MN];

/*void build(int node, int a, int b){
    if(a == b){
        tree[node] = INF;
        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1, (a+b)/2+1, b);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}*/
void upd(int node, int a, int b, int i, int j, ll val){
    if(a > j || b < i || b < a) return;
    
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(i <= a && b <= j){
        tree[node] += val;
        if(a != b){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }

    upd(node*2, a, (a+b)/2, i, j, val);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val);
    tree[node] = min(tree[node*2]+lazy[node*2], tree[node*2+1]+lazy[node*2+1]);
}
int que(int node, int a, int b, int i, int j){
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(a > j || b < i || b < a) return INF;

    if(i <= a && b <= j){
        return tree[node];
    }
    
    ll q1 = que(node*2, a, (a+b)/2, i, j);
    ll q2 = que(node*2+1, 1+(a+b)/2, b, i, j);
    return min(q1, q2);
}
//find rightmost index equal to val
int fd(int node, int a, int b, int val){
    if(b<a) return -1;

    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    //cout << "in fd " << a << " " << b << " " << tree[node] << "\n";

    if(tree[node] > val) return -1;
    if(a == b) return a;

    int res1 = fd(node*2+1, 1+(a+b)/2, b, val);
    if(res1 != -1) return res1;
    return fd(node*2, a, (a+b)/2, val);
}

void add(int i){
    //cout << "adding " << i << "\n";
    if(ct[i] == 0){
        upd(1, 1, MS, i, i, -INF);
        //cout << i << " " << i << " " << -INF << "\n";
    }
    
    upd(1, 1, MS, 1, i, -1);
    //cout << 1 << " " << i << " " << -1 << "\n";
    ++ct[i];
}
void rem(int i){
    if(ct[i] == 1){
        upd(1, 1, MS, i, i, INF);
        //cout << i << " " << i << " " << INF << "\n";
    }
    
    upd(1, 1, MS, 1, i, 1);
    //cout << "1 " << i << " 1\n";
    --ct[i];
}

void rec(int node, int a, int b){
    if(lazy[node] != 0){
        tree[node] += lazy[node];
        if(a != b){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(a == b){
        cout << tree[node] << " ";
        return;
    }
    rec(node*2, a, (a+b)/2);
    rec(node*2+1, 1+(a+b)/2, b);
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    //build(1, 1, MS);
    memset(tree, 0x3f, sizeof tree);
    FOR(i, 1, n){
        cin >> a[i];
        add(a[i]);
        
        /*cout << i << "\n";
        FOR(j, 1, 19){
            cout << tree[j] << " " << lazy[j] << "\n";
        }*/
        //cout << tree[1] << " " << lazy[1] << "\n";
    }
    /*rec(1, 1, MS);
    cout << "\n";
    FOR(j, 1, 25){
        cout << tree[j] << " ";
    }
    cout << "\n";*/
    FOR(i, 1, m){
        cin >> b[i];
        upd(1, 1, MS, 1, b[i], 1);
        //cout << "1 " << b[i] << " 1\n";
    }
    /*rec(1, 1, MS);
    cout << "\n";
    FOR(j, 1, 25){
        cout << tree[j] << " ";
    }
    cout << "\n";*/
    int q;
    cin >> q;
    F0R(_, q){
        int c;
        cin >> c;
        if(c == 1){
            int i, x;
            cin >> i >> x;
            rem(a[i]);
            add(x);
            a[i] = x;
        } else{
            int i, x;
            cin >> i >> x;
            upd(1, 1, MS, 1, b[i], -1);
            //cout << "1 " << b[i] << " -1\n";
            upd(1, 1, MS, 1, x, 1);
            //cout << "1 " << x << " 1\n";
            b[i] = x;
        }
        /*rec(1, 1, MS);
        cout << "\n";*/
        cout << fd(1, 1, MS, -1) << "\n";
    }

    return 0;
}