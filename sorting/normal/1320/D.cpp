#include <bits/stdc++.h>

using namespace std;

const int k_N = 2e5 + 7;

typedef long long ll;

struct Segment_Tree{
    array<ll, 4> nodes[4 * k_N];

    static const long long k_Mod = 1000000711, k_Base = 5;
    long long power[4 * k_N];

    array<ll, 4> merge(array<ll, 4> l, array<ll, 4> r){
        array<ll, 4> answer;
        for(int i = 0; i < 2; ++i){
            answer[i] = l[i] + (r[i] * power[l[i + 2]] % k_Mod);
            answer[i] %= k_Mod;
        }
        for(int i = 2; i < 4; ++i)
            answer[i] = l[i] + r[i];

        return answer;
    }

    Segment_Tree(){
        power[0] = 1;
        for(int i = 1; i < 4 * k_N; ++i)
            power[i] = (power[i - 1] * k_Base) % k_Mod;
    }

    void update(int index, int l, int r, int s){
        if(s < l || r < s)
            return;
        if(l == r){
            nodes[index][0] = s & 1;
            nodes[index][1] = !(s & 1);

            nodes[index][2] = !nodes[index][0];
            nodes[index][3] = !nodes[index][1];
            return;
        }

        int mid = (l + r) >> 1;
        update(2 * index + 1, l, mid, s);
        update(2 * index + 2, mid + 1, r, s);

        nodes[index] = merge(nodes[2 * index + 1], nodes[2 * index + 2]);
    }

    array<long long, 4> query_p(int index, int l, int r, int sl, int sr){
        if(r < sl || l > sr)
            return {0, 0, 0, 0};
        if(sl <= l && r <= sr)
            return nodes[index];

        int mid = (l + r) >> 1;
        array<ll, 4> l_val = query_p(2 * index + 1, l, mid, sl, sr);
        array<ll, 4> r_val = query_p(2 * index + 2, mid + 1, r, sl, sr);

        return merge(l_val, r_val);
    }

    long long query(int index, int l, int r, int sl, int sr){
        return query_p(index, l, r, sl, sr)[sl & 1];
    }
};

int n, q;
string t;

int prefix[k_N];
Segment_Tree st;

int get_sum(int l, int r){
    if(l == 0)
        return prefix[r];
    return prefix[r] - prefix[l - 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> t;

    prefix[0] = t[0] - '0';
    for(int i = 1; i < n; ++i)
        prefix[i] = (t[i] - '0') + prefix[i - 1];

    for(int i = 0; i < n; ++i)
        if(t[i] == '0')
            st.update(0, 0, n - 1, i);

    cin >> q;
    for(int i = 0; i < q; ++i){
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        l1--;
        l2--;

        int l1_end = l1 + len - 1;
        int l2_end = l2 + len - 1;

        if(get_sum(l1, l1_end) != get_sum(l2, l2_end)){
            cout << "No\n";
            continue;
        }

        bool ok = (st.query(0, 0, n - 1, l1, l1_end) == st.query(0, 0, n - 1, l2, l2_end));

        cout << (ok ? "Yes" : "No") << "\n";
    }
}