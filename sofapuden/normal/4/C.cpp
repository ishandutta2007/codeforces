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
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    map<string,int> us;
    rep(i, 0, n) {
        string s;
        cin >> s;
        if (us.find(s) == us.end()) { cout << "OK\n"; us[s] = 0; }
        else { cout << s << us[s] << "\n"; }
        us[s]++;
    }
    return 0;
}