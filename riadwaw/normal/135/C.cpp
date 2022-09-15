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
string s;

int arr[200];
void solve() {
    cin>>s;
    int n=s.length();
    int m=(n-2+1)/2;
    int v=(n-2)/2;

    for(int i=0;i<n;++i){
        ++arr[s[i]];
    }
    if(arr['0']+arr['?']>=v+2)
        cout<<"00"<<endl;

    if(arr['1']+arr['?']>m && arr['0']+arr['?']>v){
        if(s[n-1]!='0' && (s[n-1]=='1' || arr['1']<=m))
            cout<<"01"<<endl;
        if(s[n-1]!='1' && (s[n-1]=='0' || arr['0']<=v))
            cout<<"10"<<endl;
    }

    if(arr['1']+arr['?']>=m+2 )
        cout<<"11"<<endl;
}