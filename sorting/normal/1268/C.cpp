#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 3;

struct Fenwick{
    long long a[k_N + 10];

    void update(int i, long long d){
        for(++i; i < k_N + 10; i += i & -i)
            a[i] += d;
    }

    long long query(int i){
        long long answer = 0;
        for(++i; i >= 1; i -= i & -i)
            answer += a[i];
        return answer;
    }

    long long query(int l, int r){
        return query(r) - query(l - 1);
    }
};

struct SegmentTree{
    long long sum[4 * k_N], lp[4 * k_N];

    void push_lazy(int index, int l, int r){
        if(lp[index]){
            sum[index] += lp[index] * (r - l + 1);
            if(l != r){
                lp[2 * index + 1] += lp[index];
                lp[2 * index + 2] += lp[index];
            }
            lp[index] = 0;
        }
    }

    void update(int index, int l, int r, int sl, int sr, int val){
        push_lazy(index, l, r);

        if(sl > r || sr < l)
            return;
        if(sl <= l && r <= sr){
            lp[index] += val;
            push_lazy(index, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * index + 1, l, mid, sl, sr, val);
        update(2 * index + 2, mid + 1, r, sl, sr, val);

        sum[index] = sum[2 * index + 1] + sum[2 * index + 2];
    }

    long long query(int index, int l, int r, int sl, int sr){
        push_lazy(index, l, r);

        if(sl > r || sr < l)
            return 0;
        if(sl <= l && r <= sr)
            return sum[index];

        int mid = (l + r) >> 1;
        long long lvalue = query(2 * index + 1, l, mid, sl, sr);
        long long rvalue = query(2 * index + 2, mid + 1, r, sl, sr);

        return lvalue + rvalue;
    }
};

int n;
int pos[k_N], p[k_N];

long long dist[k_N], inv[k_N];

Fenwick f;

SegmentTree l_st, r_st;
set<int> l_set, r_set;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> p[i];
        p[i]--;
    }

    for(int i = 0; i < n; ++i)
        pos[p[i]] = i;

    for(int i = 0; i < n; ++i){
        int p = pos[i];
        l_set.insert(p);

        if(l_set.size() > r_set.size() + 1){
            int val = *l_set.rbegin();
            l_set.erase(val);
            r_set.insert(val);
        }
        if(!l_set.empty() && !r_set.empty() && *l_set.rbegin() > *r_set.begin()){
            int lval = *l_set.rbegin();
            int rval = *r_set.begin();

            l_set.erase(lval);
            r_set.insert(lval);

            l_set.insert(rval);
            r_set.erase(rval);
        }

        l_st.update(0, 0, n - 1, 0, p - 1, 1);
        r_st.update(0, 0, n - 1, p + 1, n - 1, 1);

        int median = *l_set.rbegin();
        //cout << median << " median" << endl;
        dist[i] = r_st.query(0, 0, n - 1, 0, median) + l_st.query(0, 0, n - 1, median + 1, n - 1);
        //cout << dist[i] << " i" << endl;

        long long k = (i + 1) >> 1;
        if((i + 1) & 1)
            dist[i] -= k * k;
        else
            dist[i] -= (k - 1) * k;
    }

    long long curr = 0;
    for(int i = 0; i < n; ++i){
        curr += f.query(pos[i], k_N);
        f.update(pos[i], 1);

        inv[i] = curr;
    }

    //for(int i = 0; i < n; ++i)
    //    cout << inv[i] << " - " << dist[i] << "\n";
    //cout << "\n";

    for(int i = 0; i < n; ++i)
        cout << dist[i] + inv[i] << " ";
    cout << "\n";
}