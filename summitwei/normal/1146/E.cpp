#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 300005
#define MX 250000
#define SHF 110000
#define BND 100000
int n, q;
int a[MN];

int tree[3*MN];
pair<int, int> lazy[3*MN]; //sets, flips. only one will be on at a time

void build(int node, int a, int b){
    if(a == b){
        if(a < SHF){
            tree[node] = -1;
        } else{
            tree[node] = 1;
        }
        //cout << "set " << a << " to " << tree[node] << "\n";

        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1, 1+(a+b)/2, b);
}

void lupd(int ind, int type, int val){
    //cout << "updating " << ind << " " << type << " " << val << "\n";
    if(lazy[ind].f != 0){
        if(type == 0){
            lazy[ind].f = val;
        } else{
            lazy[ind].f = -lazy[ind].f;
        }
    } else if(lazy[ind].s != 0){
        if(type == 0){
            lazy[ind].f = val;
            lazy[ind].s = 0;
        } else{
            lazy[ind].s = 0;
        }
    } else{
        if(type == 0){
            lazy[ind].f = val;
        } else{
            lazy[ind].s = 1;
        }
    }
}

void upd(int node, int a, int b, int i, int j, int val, int type){ //0 = set, 1 = flip
    //cout << "doing " << node << " " << a << " " << b << " " << i << " " << j << " " << val << " " << type << "\n";
    if(lazy[node].f != 0){
        tree[node] = lazy[node].f;
        if(a != b){
            //lazy[node*2] = lazy[node];
            //lazy[node*2+1] = lazy[node];
            lupd(node*2, 0, lazy[node].f);
            lupd(node*2+1, 0, lazy[node].f);
        }
        lazy[node].f = 0;
    } else if(lazy[node].s != 0){
        tree[node] *= -1;
        if(a != b){
            lupd(node*2, 1, lazy[node].s);
            lupd(node*2+1, 1, lazy[node].s);
        }
        lazy[node].s = 0;
    }
    
    if(a > j || b < i || a > b) return;
    
    if(i <= a && b <= j){
        //tree[node] = val;
        if(type == 0){
            tree[node] = val;
        } else{
            tree[node] *= -1;
        }
        if(a != b){
            //lazy[node*2] = val;
            //lazy[node*2+1] = val;
            lupd(node*2, type, val);
            lupd(node*2+1, type, val);
        }
        return;
    }

    upd(node*2, a, (a+b)/2, i, j, val, type);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val, type);
}
int vals[MN];
void rec(int node, int a, int b){
    if(lazy[node].f != 0){
        tree[node] = lazy[node].f;
        if(a != b){
            //lazy[node*2] = lazy[node];
            //lazy[node*2+1] = lazy[node];
            lupd(node*2, 0, lazy[node].f);
            lupd(node*2+1, 0, lazy[node].f);
        }
        lazy[node].f = 0;
    } else if(lazy[node].s != 0){
        tree[node] *= -1;
        if(a != b){
            lupd(node*2, 1, lazy[node].s);
            lupd(node*2+1, 1, lazy[node].s);
        }
        lazy[node].s = 0;
    }
    
    if(a == b){
        vals[a] = tree[node];
        //cout << "sign for " << a << " is " << tree[node] << "\n";
    } else{
        rec(node*2, a, (a+b)/2);
        rec(node*2+1, 1+(a+b)/2, b);
    }
}

void doUpd(int a, int b, int type, int val){
    //upd(1, 1, MX, a+SHF, b+SHF, type);
    if(type == 0){
        //cout << "setting " << a << " " << b << " to " << val << "\n";
        upd(1, 1, MX, a+SHF, b+SHF, val, type);
    } else{
        //cout << "flipping " << a << " " << b << "\n";
        upd(1, 1, MX, a+SHF, b+SHF, val, type);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    F0R(i, n){
        cin >> a[i];
    }

    build(1, 1, MX);

    F0R(i, q){
        char s; int x;
        cin >> s >> x;

        if(s == '<'){
            if(x > 0){
                doUpd(-BND, -x, 0, 1);
                doUpd(-x+1, x-1, 1, 1);
                doUpd(x, BND, 0, 1);
            } else{
                doUpd(-BND, x-1, 0, 1);
                doUpd(-x+1, BND, 0, 1);
            }
        } else{
            if(x < 0){
                doUpd(-x, BND, 0, -1);
                doUpd(x+1, -x-1, 1, 1);
                doUpd(-BND, x, 0, -1);
            } else{
                doUpd(x+1, BND, 0, -1);
                doUpd(-BND, -x-1, 0, -1);
            }
        }
    }

    rec(1, 1, MX);

    F0R(i, n){
        int v = a[i];
        if((vals[v+SHF] == 1) == (v >= 0)){
            cout << v << " ";
        } else{
            cout << -v << " ";
        }
    }
    cout << "\n";
    
    return 0;
}