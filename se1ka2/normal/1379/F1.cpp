#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){   // sum of [0, i)
        T res = 0;
        while(i){
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            bit[i] += x;
            i += (i & -i);
        }
    }
};

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    P p[200005];
    for(int c = 0; c < q; c++){
        int i, j;
        cin >> i >> j;
        p[c] = P(i, j);
    }
    int right = q + 1, left = 0;
    while(right - left > 1){
        int mid = (right + left) / 2;
        priority_queue<P> que;
        for(int c = 0; c < mid; c++) que.push(p[c]);
        BIT<int> bit(400005);
        bool f = true;
        while(que.size()){
            P r = que.top();
            que.pop();
            if(r.first % 2){
                if(bit.sum(400003) - bit.sum(r.second)) f = false;
            }
            else{
                bit.add(r.second, 1);
            }
        }
        if(!f) right = mid;
        else left = mid;
    }
    for(int i = 0; i < left; i++) cout << "YES" << endl;
    for(int i = left; i < q; i++) cout << "NO" << endl;
}