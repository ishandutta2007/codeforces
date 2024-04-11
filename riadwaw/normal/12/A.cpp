#include <set>
#include <map>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
typedef pair<int,int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    solve();
    return 0;
}
void solve(){
    char s[5][5];
    for(int i=0;i<3;i++)
        cin>>s[i];
    bool f=true;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(s[i][j]!=s[2-i][2-j])
                f=false;
    cout<<(f?"YES":"NO");
        
}