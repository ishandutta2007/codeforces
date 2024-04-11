//SOMETHING SOMETHING DEBUG THIS CRAP

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

int tree[3*MAX_N];
int lazy[3*MAX_N];
bool reset[3*MAX_N];
int n;

void update(int node, int a, int b, int l, int r, int val){
    /*if(reset[node] != -1){
        tree[node] = 0;
        lazy[node] = reset[node];
        if(a!=b){
            reset[2*node] = 0;
            reset[2*node+1] = 0;
        }
        reset[node] = -1;
    }*/
    if(reset[node]){
        if(a != b){
            tree[2*node] = 0;
            tree[2*node+1] = 0;
            lazy[2*node] = 0;
            lazy[2*node+1]=0;
            reset[2*node]=true;
            reset[2*node+1]=true;
        }
        reset[node] = false;
    }
    

    if(lazy[node] != 0){
        tree[node] += lazy[node];

        if(a!=b){
            /*if(reset[node*2] == 0){
                reset[node*2] = lazy[node];
            } else{
                lazy[node*2]+=lazy[node];
            }
            if(reset[node*2+1] == 0){
                reset[node*2+1] = lazy[node];
            } else{
                lazy[node*2+1]+=lazy[node];
            }*/
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(a > r || b < l || a > b) return;

    if(a >= l && b <= r){
        tree[node] += val;
        if(a!=b){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }

    update(node*2, a, (a+b)/2, l, r, val);
    update(node*2+1, (a+b)/2+1, b, l, r, val);

    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int a, int b, int x){
    /*if(reset[node] != -1){
        tree[node] = 0;
        lazy[node] = reset[node];
        if(a!=b){
            reset[2*node] = 0;
            reset[2*node+1] = 0;
        }
        reset[node] = -1;
    }*/
    if(reset[node]){
        if(a != b){
            tree[2*node] = 0;
            tree[2*node+1] = 0;
            lazy[2*node] = 0;
            lazy[2*node+1]=0;
            reset[2*node]=true;
            reset[2*node+1]=true;
        }
        reset[node] = false;
    }

    if(lazy[node] != 0){
        tree[node] += lazy[node];

        if(a!=b){
            /*if(reset[node*2] == 0){
                reset[node*2] = lazy[node];
            } else{
                lazy[node*2]+=lazy[node];
            }
            if(reset[node*2+1] == 0){
                reset[node*2+1] = lazy[node];
            } else{
                lazy[node*2+1]+=lazy[node];
            }*/
            lazy[node*2+1] += lazy[node];
            lazy[node*2] += lazy[node];
        }
        lazy[node] = 0;
    }

    if(a == b){
        return tree[node];
    }

    if((a+b)/2 >= x){
        return query(node*2, a, (a+b)/2, x);
    } else{
        return query(node*2+1, (a+b)/2+1, b, x);
    }
}

struct Query{
    int val;
    int loc;
    int type;
    int time;
    int output;
};
bool comp(Query a, Query b){
    if(a.val != b.val) return a.val < b.val;
    return a.loc < b.loc;
}

bool comp2(Query a, Query b){
    return a.loc < b.loc;
} //this is used when we're putting things back into order for the purposes of things

bool compRess(Query a, Query b){
    return a.time < b.time;
}


Query qs[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> qs[i].type >> qs[i].time >> qs[i].val;
        qs[i].loc = i;
    }

    /*for(int i=0; i<n; i++){
        cout << qs[i].val << " " << qs[i].loc << " " << qs[i].type << " " << qs[i].time << "\n";
    }*/
    
    sort(qs, qs+n, compRess);
    for(int i=0; i<n; i++){
        qs[i].time = i+1;
    } //this compresses the time which is nice, and also puts it at one

    sort(qs, qs+n, comp);

    //cout << "hi\n";

    int prev = qs[0].val;
    for(int i=0; i<n; i++){
        //cout << "doing " << i << "\n";
        //cout << qs[i].val << " " << qs[i].loc << " " << qs[i].type << " " << qs[i].time << "\n";
        if(qs[i].val != prev){
            reset[1] = true;
            tree[1] = 0;
            lazy[1] = 0;
            prev = qs[i].val;
        }

        if(qs[i].type == 1){
            update(1, 1, n, qs[i].time, n, 1);
        } else if(qs[i].type == 2){
            update(1, 1, n, qs[i].time, n, -1);
        } else{
            qs[i].output = query(1, 1, n, qs[i].time);
        }

        /*for(int j=1; j<n*2; j++){
            cout << tree[j] << " ";
        }
        cout << "\n";
        for(int j=1; j<n*2; j++){
            cout << lazy[j] << " ";
        }
        cout << "\n";*/
    }

    //cout << "hi\n";

    sort(qs, qs+n, comp2);
    for(int i=0; i<n; i++){
        if(qs[i].type == 3){
            cout << qs[i].output << "\n";
        }
    }

    return 0;
}