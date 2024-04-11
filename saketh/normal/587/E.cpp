#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

template<typename T> struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S, T _zero = T()) {
        S = _S, zero = _zero;
        value.resize(2*S+1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--) 
            value[i] = value[2 * i] + value[2 * i + 1];
    }

    void upd(int i, T v) {
        i += S;
        value[i] = v;
        while(i>1){
            i/=2;
            value[i] = value[2*i] + value[2*i+1];
        }
    }

    T query(int i, int j) {
        T res_left = zero, res_right = zero;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    vector<T> value;
 
    U noop;
    vector<bool> dirty;
    vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }
 
    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
 
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }
 
    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
    void rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
    void propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
 
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
 
                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }
 
    void upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
    T query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

void gauss(vector<ui> &vals) {
    int tail = 0;
    for (int i = 0; i < 32; i++) {
        int ch = -1;
        for (int j = tail; j < vals.size(); j++)
            if ((vals[j] >> i)&1) {
                ch = j;
                break;
            }
                
        if (ch != -1) {
            swap(vals[ch], vals[tail]);
            for (int j = tail + 1; j < vals.size(); j++)
                if ((vals[j] >> i)&1)
                    vals[j] ^= vals[tail];
            tail++;
        }
    }       
    vals.resize(tail);
}

struct vertexB {
    vector<ui> basis;
    vertexB() { }
    vertexB(vector<ui> _basis) { basis = _basis; }
    vertexB operator+(vertexB &v) {
        vertexB res;
        res.basis.insert(res.basis.end(), basis.begin(), basis.end());
        res.basis.insert(res.basis.end(), v.basis.begin(), v.basis.end());
        gauss(res.basis);
        return res;
    }
};

struct vertexA {
    ui val;
    vertexA(ui _val = 0) { val = _val; }
    vertexA operator+(vertexA &v) {
        return vertexA(val ^ v.val);
    }
};

struct update {
    ui w;
    update (ui _w = 0){ w = _w; }
    update operator+(const update &u) { return update( w ^ u.w); };
    vertexA operator()(const vertexA &v) {
        return vertexA(v.val ^ w);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int N, Q;
    cin >> N >> Q;

    vector<vertexA> leavesA(N);
    vector<vertexB> leavesB(N-1);

    vector<ui> diffs(N-1);

    ui V;
    for (int i = 0; i < N; i++) {
        cin >> V;
        leavesA[i] = vertexA(V);
        if (i) {
            diffs[i-1] = leavesA[i-1].val ^ V;
            leavesB[i-1] = vertexB({ diffs[i-1] });
        }
    }

    seg_tree_lazy<vertexA, update> segA(N);
    segA.set_leaves(leavesA);

    seg_tree<vertexB> segB(N-1);
    segB.set_leaves(leavesB);

    int T, L, R;
    ui K;
    for (int i = 0; i < Q; i++) {
        cin >> T >> L >> R;
        L--, R--;

        if (T == 1) {
            cin >> K;
            segA.upd(L, R, {K});

            if (L) {
                diffs[L-1] ^= K;
                segB.upd(L-1, {{ diffs[L-1] }});
            }
            if (R < N - 1) {
                diffs[R] ^= K;
                segB.upd(R, {{ diffs[R] }});
            }
        } else {
            vector<ui> basis(0);
            if (R > L) basis = segB.query(L, R-1).basis;
            basis.push_back(segA.query(L, L).val);
            gauss(basis);
            cout << (1ll << basis.size()) << "\n";
        }
    }
}