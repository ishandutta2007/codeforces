#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
typedef double ld;
void solve();

#define mp make_pair
#define pb push_back
int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
bool a[2][8];
void solve(){
    char s[10][10];
    int ans=0,add=0;
    for(int i=0;i<8;++i){
        cin>>s[i];
        int c=0;
        for(int j=0;j<8;++j){
            if(s[i][j]=='B'){
                ++c;
            }
        }
        if(c==8)
            ++ans;
        else if(!add){
            add=c;
        }
    }
    cout<<ans+add;
}