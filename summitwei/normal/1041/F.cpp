#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_PER 200005
#define MAX_N 100005

int top[MAX_N];
int bot[MAX_N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, y1;
    cin >> n >> y1;
    for(int i=0; i<n; i++){
        cin >> top[i];
    }

    int m, y2;
    cin >> m >> y2;
    for(int i=0; i<m; i++){
        cin >> bot[i];
    }

    int ans = 2;
    for(int i=1; i<=INF; i*=2){
        //cout << "doing " << i << "\n";
        map<int, int> cnts;
        for(int j=0; j<n; j++){
            int blah = (top[j]+i)%(2*i);
            //cout << "blah is " << blah << "\n";
            if(cnts.count(blah) == 0){
                cnts.insert(make_pair(blah, 1));
            } else{
                cnts[blah]++;
            }
        }

        for(int j=0; j<m; j++){
            int blah = (bot[j])%(2*i);
            if(cnts.count(blah) == 0){
                cnts.insert(make_pair(blah, 1));
            } else{
                cnts[blah]++;
            }
        }

        for(map<int, int>::iterator it = cnts.begin(); it != cnts.end(); ++it){
            //cout << "number " << it->first << " has " << it->second << "\n";
            ans = max(ans, it->second);
        }
    }

    cout << ans << "\n";

    return 0;
}