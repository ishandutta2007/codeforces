#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void setup(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
}

const int MOD = 777777777;
bool good[3][3];

struct seg_tree{
    struct node{
        int val;
        int ways[3][3];
        node(int _val = -1){
            val = _val; 
            memset(ways, 0, sizeof(ways));
            if(val == 0 || val == 1) ways[0][0] = 1;
            if(val == 0 || val == 2) ways[1][1] = 1;
            if(val == 0 || val == 3) ways[2][2] = 1;
        }
        node operator +(const node &y){
            if(val == -1) return y;
            if(y.val == -1) return *this;

            node res(4);
            memset(res.ways, 0, sizeof(res.ways));
            for(int b1=0; b1<3; b1++)
                for(int e1=0; e1<3; e1++)
                    for(int b2=0; b2<3; b2++){
                        if(!good[e1][b2]) continue;
                        for(int e2=0; e2<3; e2++){
                            ll add = ways[b1][e1] * 1ll * y.ways[b2][e2] % MOD;
                            res.ways[b1][e2] += add;
                            res.ways[b1][e2] %= MOD;
                        }
                    }     
            return res;
        }
    };

    int S;
    vector<node> arr;
    seg_tree(int _S){
        assert(__builtin_popcount(_S) == 1);
        S = _S;
        arr.resize(2*S+1);
    }

    void upd(int i, node v){
        i += S;
        arr[i] = v;
        while(i>1){
            i/=2;
            arr[i] = arr[2*i] + arr[2*i+1];
        }
    }
};

int N, M;

int main(){
    setup();
    
    cin >> N >> M;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            cin >> good[i][j];

    seg_tree st(1<<17);

    for(int i=N-1+st.S; i>=1; i--){
        if(i >= st.S) st.arr[i] = seg_tree::node(0);
        else st.arr[i] = st.arr[2*i] + st.arr[2*i+1];
    }

    for(int q=0; q<M; q++){
        int l, v;
        cin >> l >> v;
        st.upd(l-1, seg_tree::node(v));        

        int res = 0;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++){
                res += st.arr[1].ways[i][j];
                res %= MOD;
            }
        cout << res << "\n";
    }
}