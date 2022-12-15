#include <bits/stdc++.h>

using namespace std;

const long long k_Mod = 777777777;
const int k_N = 77777 + 3;

int n, m;
bool w[4][4];

inline void fast_mod(long long &x){
    x = (x >= k_Mod) ? (x % k_Mod) : x; 
}

class Segment_Tree{
private:
    struct Node{
        long long dp[4][4];
    
        Node(){}
        Node(int value){
            for(int i = 1; i <= 3; ++i)
                for(int j = 1; j <= 3; ++j)
                    dp[i][j] = 0;

            for(int i = 1; i <= 3; ++i)
                if(!value || value == i)
                    dp[i][i] = 1; 
        }

        friend Node merge(const Node &lvalue, const Node &rvalue){
            Node answer;

            for(int l = 1; l <= 3; ++l){
                for(int r = 1; r <= 3; ++r){
                    answer.dp[l][r] = 0;
                    for(int midl = 1; midl <= 3; ++midl){
                        for(int midr = 1; midr <= 3; ++midr){
                            answer.dp[l][r] += lvalue.dp[l][midl] * w[midl][midr] * rvalue.dp[midr][r];
                            fast_mod(answer.dp[l][r]);
                        }
                    }
                }
            }

            return answer;
        }
    };
private:
    Node nodes[4 * k_N];
    int n;
private:
    void initialise(int index, int l, int r){
        if(l == r){
            nodes[index] = Node(0);
            return;
        }

        int mid = (l + r) >> 1;
        initialise(2 * index + 1, l, mid);
        initialise(2 * index + 2, mid + 1, r);

        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
    }
    void update(int index, int l, int r, int s, int value){
        if(s < l || r < s)
            return;
        if(l == r){
            nodes[index] = Node(value);
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * index + 1, l, mid, s, value);
        update(2 * index + 2, mid + 1, r, s, value);

        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
    }
public:
    Segment_Tree(){}
    void resize(int n){
        this->n = n;
        initialise(0, 1, n);
    }
    void update(int index, int value){
        update(0, 1, n, index, value);
    }
    long long query(){
        long long answer = 0;

        for(int l = 1; l <= 3; ++l)
            for(int r = 1; r <= 3; ++r)
                answer += nodes[0].dp[l][r];

        fast_mod(answer);

        return answer;
    }
};

Segment_Tree segment_tree;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= 3; ++i)
        for(int j = 1; j <= 3; ++j)
            cin >> w[i][j];

    segment_tree.resize(n);

    for(int i = 0; i < m; ++i){
        int v, t;
        cin >> v >> t;

        segment_tree.update(v, t);
        cout << segment_tree.query() << "\n";
    }
}