#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define INF 1000000001
constexpr int MOD = 1000000007;

struct Segment_Min {
private:
    int n;
    vector<int> node;

public:
    Segment_Min(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }

    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];

        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};

struct Segment_Max {
private:
    int n;
    vector<int> node;

public:
    Segment_Max(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    int getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];

        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int>> a;
    vector<tuple<int, int>> b;
    vector<int> at;
    vector<int> bt;
    REP(i, n) {
        int sa, ea, sb, eb;
        cin >> sa >> ea>> sb >> eb;
        a.push_back(make_tuple(sa, ea));
        b.push_back(make_tuple(sb, eb));
        at.push_back(sa);
        at.push_back(ea);
        bt.push_back(sb);
        bt.push_back(eb);
    }
    sort(at.begin(), at.end());
    sort(bt.begin(), bt.end());
    map<int, int> am;
    map<int, int> bm;
    int val = 0;
    REP(i, at.size()) {
        if(i != 0 && at[i] == at[i-1]) continue;
        am[at[i]] = val;
        val++;
    }
    val = 0;
    REP(i, bt.size()) {
        if(i != 0 && bt[i] == bt[i-1]) continue;
        bm[bt[i]] = val;
        val++;
    }
    REP(i, n) {
        get<0>(a[i]) = am[get<0>(a[i])];
        get<1>(a[i]) = am[get<1>(a[i])];
    }
    REP(i, n) {
        get<0>(b[i]) = bm[get<0>(b[i])];
        get<1>(b[i]) = bm[get<1>(b[i])];
    }

    vector<int> br_min(200001, INF);
    vector<int> bl_max(200001, 0);
    REP(i, n) {
        if(get<1>(b[i]) < br_min[get<0>(a[i])]) br_min[get<0>(a[i])] = get<1>(b[i]);
        if(get<0>(b[i]) > bl_max[get<0>(a[i])]) bl_max[get<0>(a[i])] = get<0>(b[i]);
    }
    Segment_Min segbrmin = Segment_Min(br_min);
    Segment_Max segblmax = Segment_Max(bl_max);
    REP(i, n) {
        //cout << get<0>(a[i]) << " " << get<1>(a[i]) << " " << get<0>(b[i]) << " " << get<1>(b[i]) << endl; 
        //cout << segblmax.getmax(get<0>(a[i]), get<1>(a[i])+1) << endl;
        if(segbrmin.getmin(get<0>(a[i]), get<1>(a[i])+1) < get<0>(b[i]) || segblmax.getmax(get<0>(a[i]), get<1>(a[i])+1) > get<1>(b[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }

    vector<int> ar_min(200001, INF);
    vector<int> al_max(200001, 0);
    REP(i, n) {
        if(get<1>(a[i]) < ar_min[get<0>(b[i])]) ar_min[get<0>(b[i])] = get<1>(a[i]);
        if(get<0>(a[i]) > al_max[get<0>(b[i])]) al_max[get<0>(b[i])] = get<0>(a[i]);
    }
    Segment_Min segarmin = Segment_Min(ar_min);
    Segment_Max segalmax = Segment_Max(al_max);
    REP(i, n) {
        if(segarmin.getmin(get<0>(b[i]), get<1>(b[i])+1) < get<0>(a[i]) || segalmax.getmax(get<0>(b[i]), get<1>(b[i])+1) > get<1>(a[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}