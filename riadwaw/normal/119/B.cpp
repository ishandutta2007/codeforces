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
typedef pair<int, int> pi;
typedef long long li;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}

int a[111];
vector<vi> old;
vi freee,var;
bool used[111];
void solve(){
    int n,k;
    cin>>n>>k;
    int intick=n/k;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int q;
    cin>>q;
    for(int tt=0;tt<q;++tt){
        int a;
        cin>>a;
        --a;
        if(used[a]){
            for(int i=1;i<intick;++i){
                int x;
                cin>>x;
        }
            continue;
        }
        used[a]=true;
        old.pb(vi(intick));
        old.back()[0]=a;
        for(int i=1;i<intick;++i){
            cin>>old.back()[i];
            --old.back()[i];
            used[old.back()[i]]=true;
        }
    }
    if(int(old.size())!=k){
        for(int i=0;i<n;++i){
            if(!used[i]){
                freee.pb(a[i]);
            }
        }

        sort(freee.begin(),freee.end());
        int s=0;
        for(int i=0;i<intick;++i){
            s+=freee[i];
        }
        var.pb(s);
        s=0;
        for(int i=int(freee.size())-1;i>=int(freee.size())-intick;--i){
            s+=freee[i];
        }
        var.pb(s);
    }


    for(int i=0;i<(int)old.size();++i){
        int s=0;
        for(int j=0;j<(int)old[i].size();++j){
            s+=a[old[i][j]];
        }
        var.pb(s);
    }
    sort(var.begin(),var.end());
    
    printf("%.10lf %.10lf",(var[0])/(double)intick,var.back()/(double)intick);
}