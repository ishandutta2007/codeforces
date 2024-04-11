#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef long long ll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define MAX_N 100005

#define F0R(i, a) for (int i=0; i<(a); i++)

set<int> poss;
unordered_map<int, int> nums;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        string s;
        cin >> s;

        int fin = 0;
        F0R(j, s.length()){
            fin ^= (1 << (s[j]-'a'));
        }
        //cout << "found " << fin << "\n";
        nums[fin]++;
        poss.insert(fin);
    }

    /*for(auto u : nums){
        cout << u.first << " " << u.second << "\n";
    }*/

    //cout << "hmm\n";

    ll eqPair = 0;
    ll btwn = 0;
    for(auto u : poss){
        //cout << "doing this loop\n";
        int here = nums[u];
        eqPair += (1LL*(here)*(here-1)/2);

        F0R(i, 26){
            int other = u ^ (1<<i);
            if(nums.count(other) != 0){
                btwn += (1LL*here*nums[other]);
            }
        }
    }

    //cout << eqPair << " " << btwn << "\n";
    cout << eqPair + btwn/2 << "\n";

    return 0;
}