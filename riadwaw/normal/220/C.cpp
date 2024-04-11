#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cassert>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <queue>
#include <stack>
using namespace std;
int cnt[256];
typedef long long li;
typedef pair<int,int> pi;
void solve();
int main(){
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    
    while(t--)
        solve();    
    return 0;
}

int a[101010];
int b[101010];
int wa[101010], wb[101010];
void solve(){
    

    int n = 1000;
    cin>>n;
    for(int i =0; i < n ;++i){
        cin>>a[i];
        --a[i];
        wa[a[i]]=i;
    }

    for(int i =0; i < n ;++i){
        cin>>b[i];
        --b[i];
        wb[b[i]]=i;
    }
    map<int, int> r;
    for(int i = 0; i < n ;++i){
        r[wb[i] - wa[i]]++;
    }

    for(int i = 0; i < n; ++i){
        map<int,int>::iterator it = r.lower_bound(i);

        /*for(multiset<int>::iterator j = r.begin(); j!= r.end(); ++j){
            cout<<*j + i<<' ';
        }
        cout<<endl;*/
        int best = 1000000000;
        if(it!=r.end())
            best = min(best, abs((it->first) - i));
        if(it!=r.begin()){
            --it;
            best = min(best, abs((it->first) - i));
        }
        assert(best != 1000000000);
        cout<<best<<'\n';
        int perehod = b[i];
        r[wb[perehod] - wa[perehod]] --;
        if(r[wb[perehod] - wa[perehod]]==0){
            r.erase(wb[perehod] - wa[perehod]);
        }
        r[wb[perehod] - wa[perehod] + n] ++;
    }
}