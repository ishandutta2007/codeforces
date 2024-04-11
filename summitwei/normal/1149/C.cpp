#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define INF 1000000000
#define MOD 998244353LL
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n, q;
string s;

struct Bruh{
    int curd;
    int a; //also c
    int b;
    int ab;
    int bc;
    int abc;
};
void op(Bruh x){
    cout << x.curd << " " << x.a << " " << x.b << " " << x.ab << " " << x.bc << " " << x.abc << "\n";
}

Bruh tree[MN*6];
Bruh merge(Bruh a, Bruh b){
    Bruh ans;
    ans.curd = a.curd+b.curd;
    ans.a = max(a.a, a.curd+b.a);
    ans.b = max(a.b, a.curd*-2+b.b);
    ans.ab = max(max(a.ab, b.ab-a.curd), a.a+b.b-2*a.curd);
    ans.bc = max(max(a.bc, b.bc-a.curd), a.b+b.a+a.curd);
    ans.abc = max(max(a.abc, b.abc), max(a.a+b.bc-a.curd, a.ab+b.a+a.curd));
    /*if(ans.ab < -INF) ans.ab = -INF;
    if(ans.bc < -INF) ans.bc = -INF;
    if(ans.abc < -INF) ans.abc = -INF;*/
    //op(a);
    //op(b);
    //op(ans);
    return ans;
}

void upd(int node, int a, int b, int i, int j, int val){
    if(a > b || a > j || b < i) return;

    if(a == b){
        tree[node].curd = tree[node].a = val;
        tree[node].b = val*-2;
        tree[node].ab = tree[node].bc = -val;
        tree[node].abc = 0;
        return;
    }
 
    upd(node*2, a, (a+b)/2, i, j, val);
    upd(node*2+1, 1+(a+b)/2, b, i, j, val);
    tree[node] = merge(tree[node*2], tree[node*2+1]);
}
/*Bruh que(int node, int a, int b, int i, int j){
    if(a > b || a > j || b < i) return {-INF, -INF, -INF, -INF, -INF, -INF};

    if(i <= a && b <= j){
        return tree[node];
    }

    Bruh q1 = que(node*2, a, (a+b)/2, i, j);
    Bruh q2 = que(node*2+1, 1+(a+b)/2, b, i, j);
    return merge(q1, q2);
}*/

void ret(int node, int a, int b){
    cout << node << " " << a << " " << b << " ";
    op(tree[node]);
    if(a != b){
        ret(node*2, a, (a+b)/2);
        ret(node*2+1, 1+(a+b)/2, b);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    cin >> s;
    FOR(i, 1, 2*n-2){
        if(s[i-1] == '('){
            upd(1, 1, 2*n-2, i, i, 1);
        } else{
            upd(1, 1, 2*n-2, i, i, -1);
        }
    }
    /*FOR(i, 1, 20){
        cout << i << " ";
        op(tree[i]);
    }*/
    //ret(1, 1, 2*n-2);
    cout << tree[1].abc << "\n";
    F0R(_, q){
        int x, y;
        cin >> x >> y;
        if(s[y-1] == '('){
            upd(1, 1, 2*n-2, x, x, 1);
        } else{
            upd(1, 1, 2*n-2, x, x, -1);
        }
        if(s[x-1] == '('){
            upd(1, 1, 2*n-2, y, y, 1);
        } else{
            upd(1, 1, 2*n-2, y, y, -1);
        }
        swap(s[x-1], s[y-1]);
        //ret(1, 1, 2*n-2);
        cout << tree[1].abc << "\n";
    }
    
    return 0;
}