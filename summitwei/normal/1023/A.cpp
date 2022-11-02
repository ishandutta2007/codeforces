#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 300005

int main(){
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    auto star = s.find('*');
    if(star == -1){
        if(s == t){
            cout << "YES";
        } else{
            cout << "NO";
        }

        return 0;
    }

    if(n <= m+1 && s.substr(0, star) == t.substr(0, star) && s.substr(star+1, n-star-1) == t.substr(m-n+star+1, n-star-1)){
        cout << "YES";
    } else{
        cout << "NO";
    }

    return 0;
}