#include<bits/stdc++.h>
#include<unordered_set>
#define rep(i,a,b) for(int i = a; i<b; i++)
#define dep(i,a,b) for(int i = a; i>b; i--)
#define makeUnique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin())
#define LOG_vec(vec, sep) for (int fl = 0; fl < vec.size(); fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n";
#define LOG_ints(vec, sep) for (int fl = 0; fl < MAXSIZE; fl++) { std::cout << vec[fl]<< sep; } std::cout << "\n"
#define all(x) (x).begin(), (x).end()
#define LSB(i) ((i) & -(i))
#define MAXSIZE 100000000

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
void solve() {
    int n, m; cin >> n >> m;
    rep(i, 0, n) {
        string s;
        rep(j, 0, s.length()) {

        }
    }
   
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    map<int, int> m;
    rep(i, 0, n) {
        int tmp; cin >> tmp;
        m[tmp]++;
    }
    int counter = m[4]+m[3];
    m[1] = max(0, m[1] - m[3]);
    counter += m[2] / 2;
    if (m[2] % 2 == 1) {
        counter += (m[1] + 2) / 4;
        if ((m[1] + 2) % 4 != 0) { counter++; }
    }
    else {
        counter += m[1] / 4;
        if (m[1] % 4 != 0) { counter++; }
    }
    cout << counter << "\n";
}