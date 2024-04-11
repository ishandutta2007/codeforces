#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <complex>
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
typedef double ld;
void solve();

#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
#define int li
struct comp{
    bool operator() (string a,string b){
        return a.size()>b.size() || a.size()==b.size() && a<b;
    }
};
void solve(){
    map<string,int,comp> m;
    string s;
    cin>>s;
    m[string()]=2;
    for(int i=0;i<s.length();++i){
        for(int j=0;j<=s.length()-i;++j){
            ++m[s.substr(i,j)];
        }
    }
    while(m.begin()->second<2)
        m.erase(m.begin());
    
    cout<<m.begin()->first.length();
}