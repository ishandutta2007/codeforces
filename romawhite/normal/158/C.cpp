#include <iostream> 
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define CLEAR(a) memset((a),0,sizeof((a)))
#define X first
#define Y second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;

const double pi=3.141592653589793;
const int INF=2000000000;
const int mod=1000000007;

int dp[5000][5000];

int main() {
    int n;
    cin >> n;
    vector<string> s;
    FOR(i,0,n){
        string ss;
        cin >> ss;
        if (ss == "pwd"){
            FOR(i,0,s.size())
                cout << '/' << s[i];
            cout << '/' << endl;
        }
        if (ss == "cd"){
            string s1;
            cin >> s1;
            int i=0;
            if (s1[0] == '/'){
                s.clear();
                ++i;
            }
            while (i<s1.size()){
                if (s1[i] == '.'){
                    s.pop_back();
                    i+=3;
                }
                else{
                    string s2 = "";
                    while (i<s1.size() && s1[i] >= 'a' && s1[i] <='z'){
                        s2+=s1[i];
                        ++i;
                    }
                    s.push_back(s2);
                    if (i<s1.size()) ++i;
                }
            }
        }
    }
    return 0;
}