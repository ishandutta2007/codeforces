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
#include <cstdlib>
using namespace std;
void solve();

#define pb push_back

typedef long long li;
typedef vector<int> vi;
//typedef pair<int, int> pi;

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
const double PI = 3.14159265358979323846;
int a[333][333];
int self[333];
int obr[333];
void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    for(int i=1;i<=n;++i){
        cin>>self[i];
        obr[self[i]]=i;
    }

    for(int fr=1;fr<=n;++fr){
    //  cout<<"friend "<<fr<<endl;
        bool can[333];
        memset(can,0,sizeof(can));
        int l=n+1;
        for(int card=1;card<=n;++card){
            if(fr==card)
                continue;
            if(obr[card]<l){
                //cout<<"card "<<card<<endl;
                can[card] =true;
                l=obr[card];
            }
        }
        for(int i=1;i<=n;++i){
            if(can[a[fr][i]]){
                cout<<a[fr][i]<<' ';
                break;
            }
        }
    }

}