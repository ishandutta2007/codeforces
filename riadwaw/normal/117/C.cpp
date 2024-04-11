#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
#include <complex>
#include <string.h>
#include <algorithm>
using namespace std;

void solve();
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
/**
 CAUTION Is int really int?
 *
 Real solution after main function
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

fknmain main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
#define LL "%lld"
#else
#define LL "%I64d"
#endif
#ifndef int
#define INT "%d"
#else
#define INT LL
#endif
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    solve();
    return 0;
}


struct vim{

    int l;
    int ans[5005];
    vim(){
        l=0;
    }
    int size(){
        return l;
    }
    bool empty(){
        return l==0;
    }

    void pop_back(){
        --l;
    }
    void push_back(int k){
        ans[l++]=k;
    }

    int operator[] (int k){
        return ans[k];
    }

    int* begin(){
        return ans;
    }

    int* end(){
        return ans+l;
    }
    


};
vi g[5555];
int used[5555];
vi ans;

int dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        if (used[g[v][i]] == 0) {
            int p = dfs(g[v][i]);
            if (p != -1) {
                if ((p == -2) || (p == v)) {
                    return -2;
                }
                ans.pb(v);
                return p;
            }
        } else if (used[g[v][i]] == 1) {
            ans.pb(g[v][i]);
            ans.pb(v);
            return g[v][i];
        }

    }
    used[v] = 2;
    return -1;
}
char s[5555][5555];

void solve() {


    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf(" %s ",s[i]);
        for (int j = 0; j < n; ++j) {
            
            if (s[i][j] == '1')
                g[i].pb(j);
        }
    }
    for (int i = 0; i < n && ans.empty(); ++i) {
        if (!used[i])
            dfs(i);
    }
    if (ans.empty()) {
        cout << "-1";
        return;
    }
    reverse(ans.begin(), ans.end());
    //cout<<endl;
    //for(int i=0;i<ans.size();++i)
    //  cout<<ans[i]<<' ';
    //cout<<endl;
    while (ans.size() > 3) {
        if (s[ans[0]][ans[ans.size() - 2]] == '1') {
            cout << ans[0] + 1 << ' ' << ans[ans.size() - 2] + 1 << ' ' << ans[ans.size()-1] + 1;
            return;
        }
        ans.pop_back();
    }

    cout << ans[0] + 1 << ' ' << ans[1] + 1 << ' ' << ans[2] + 1;
}