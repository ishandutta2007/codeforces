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
void solve(){   
    string s,t;
    map<char,int> m;
    getline(cin,s);
    getline(cin,t);
    for(int i=0;i<s.length();++i)
        ++m[s[i]];
    for(int i=0;i<t.length();++i){
        --m[t[i]];
    }
    for(map<char,int>::iterator it=m.begin();it!=m.end();++it)
        if(it->first!=' ' && it->second<0){
            cout<<"NO";
            return;
        }
    cout<<"YES";
}