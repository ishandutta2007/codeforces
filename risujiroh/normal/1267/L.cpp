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
int N, K, L;
map<char, int> mp;
string ans[1005];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> L >> K;
    string S;
    cin >> S;
    for(auto a : S) mp[a]++;
    int First = 1;
    char now = 'a';
    for(int index = 0; index < L; index++) {
        for(int i = First; i <= K; i++) {
            while(mp[now] == 0) now++;
            //cerr << index << " " << i << " " << now << endl;
            mp[now]--;
            ans[i].push_back(now);
        }
        while(ans[First] != ans[K]) First++;
    }
    /*
    for(int i = 1; i <= N; i++) {
        cerr << ans[i] << endl;
    }
    */
    for(int i = 1; i <= N; i++) {
        while(ans[i].size() != L) {
            while(mp[now] == 0) now++;
            mp[now]--;
            ans[i].push_back(now);
        }
    }
    sort(ans, ans + N);
    for(int i = 1; i <= N; i++) cout << ans[i] << endl;
    return 0;
}