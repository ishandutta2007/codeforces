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

void solve(){
    int n;
    cin>>n;
    map<string,int> m;
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        if(m[s])
            cout<<s<<(m[s]++)<<endl;
        else
            m[s]++,cout<<"OK\n";
    }
}