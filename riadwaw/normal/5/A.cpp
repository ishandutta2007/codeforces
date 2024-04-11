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
void solve(){
    char c;
    char a[122];
    int cnt=0,ans=0;
    while(cin>>c){
        if(c=='+'){
            cnt++;
            cin>>a;
            continue;
        }
        else if(c=='-'){
            cnt--;
            cin>>a;
        }
        else{
            cin.getline(a,100,':');
            cin.getline(a,100);
            ans+=strlen(a)*cnt;
        }
    }
    cout<<ans;
}