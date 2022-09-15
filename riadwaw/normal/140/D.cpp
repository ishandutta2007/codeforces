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
#define mp make_pair

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
map<int,int> m;
void solve() {
    int n;
    cin>>n;
    int a[1000];
    int s[1000];
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    s[0]=0;
    for(int i=1;i<=n;++i){
        s[i]=s[i-1]+a[i-1];
        if(s[i]>710)
            n=i-1;
    }
    cout<<n<<' ';
    int ans=0;
    for(int i=1;i<=n;++i){
        if(s[i]>=350){
            ans+=s[i]-350;
        }
    }

    cout<<ans;

}