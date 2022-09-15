#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
li cnt[30];
int let[30];
const int maxlen = 101010;
map<int,int> m;
void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        m[x]++;
    }

    while(m.size()>2){
        if(m[m.begin()->first+1] < m.begin()->second + 1){
            cout<<"NO";
            return;
        }
        m[m.begin()->first+1]-=m.begin()->second;
        m.erase(m.begin());
    }

    if(m.size() == 2 && m[m.begin()->first+1] == m.begin()->second){
        cout<<"YES";
    }
    else
        cout<<"NO";

}