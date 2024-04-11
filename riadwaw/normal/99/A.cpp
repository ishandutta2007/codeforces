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
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
char s[100][100];
void solve(){
    string s;
    cin>>s;
    int a=find(s.begin(),s.end(),'.')-s.begin();
    if(s[a-1]=='9')
        cout<<"GOTO Vasilisa.";
    else{
        if(s[a+1]>='5')
            s[a-1]++;
        cout<<string(s.begin(),s.begin()+a);
    }

}