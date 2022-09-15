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
int reverse(int h){
    int res=0;
    for(int i=0;i<8;++i){
        if((1<<i)&h){
            res+=1<<(7-i);
        }
    }
    return res;
}
void solve(){
    int p=0;
    while(true){
        int c=getchar();
        if(c<32 || c>126)
            return;
        int need=reverse(c);
        
        cout<<(p-need+256)%256<<endl;
        p=need;
    }
}