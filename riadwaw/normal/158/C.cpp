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
#include <cassert>

using namespace std;
void solve();

#define pb push_back
#define mp make_pair

typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif

    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
vector<string> v;
string s;
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>s;
        if(s=="pwd"){
            cout<<"/";
            for(int i=0;i<(int)v.size();++i){
                cout<<v[i]<<"/";
            }
            cout<<endl;
        }
        else{
            cin>>s;
            if(s[0]=='/'){
                v.clear();
                s=s.substr(1);
            }
            s+='/';
            int f=0;
            for(int i=0;i<(int)s.size();++i){
                if(s[i]=='/'){
                    string dir = s.substr(f,i-f);
                    //cout<<"dir="+dir<<endl;
                    if(dir=="..")
                        v.pop_back();
                    else
                        v.push_back(dir);
                    f=i+1;
                }
            }
        }
    }
}