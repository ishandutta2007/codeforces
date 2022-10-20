#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N, M;
int a[105][105];
int ansnum = 1e9;
vector<int> ansv;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> a[i][j];
        }
    }
    for(int person = 1; person < N; person++) {
        int delta = 0;
        vector<i_i> v;
        for(int i = 1; i <= M; i++) {
            delta += a[i][N] - a[i][person];
            v.push_back({a[i][person] - a[i][N], i});
        }
        sort(v.begin(), v.end());
        int index = 0;
        while(delta > 0) {
            delta += v[index].first;
            index++;
        }
        //cerr << person << " " << index << endl;
        if(index < ansnum) {
            ansv.clear();
            for(int i = 0; i < index; i++) {
                ansv.push_back(v[i].second);
            }
            ansnum = index;
        }
    }
    cout << ansv.size() << endl;
    for(int i = 0; i < ansv.size(); i++) {
        cout << ansv[i] << " ";
    }
    cout << endl;
    return 0;
}