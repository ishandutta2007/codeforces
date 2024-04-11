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
//typedef pair<int, int> pi;

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

void solve() {
    int n,k;
    string s[12000];
    cin>>n>>k;
    for(int i=0;i<4*n;++i){
        cin>>s[i];
        int c=0;
        for(int j=s[i].length();j>=0;--j){
            if(s[i][j]=='o' || s[i][j]=='e' || s[i][j]=='i' || s[i][j]=='a' || s[i][j]=='u'){
                ++c;
                if(c==k){
                    s[i]=s[i].substr(j,100101);
                    break;
                }
            }
        }
        if(c<k){
            cout<<"NO";
            return;
        }
    }

    bool f=true;
    for(int i=0;i<4*n;++i){
        if(s[i]!=s[i/4*4]){
            f=false;
            break;
        }
    }
    if(f){
        cout<<"aaaa";
        return;
    }

    f=true;
    for(int i=0;i<4*n;++i){
        if(s[i]!=s[i/4*4 + (i%2)]){
            f=false;
            break;
        }
    }
    if(f){
        cout<<"abab";
        return;
    }

    f=true;
    for(int i=0;i<4*n;++i){

        if(i%4 == 0 || i%4==3) {
            if(s[i]!=s[i/4*4]){
                f=false;
                break;
            }
        }
        else {
            if(s[i]!=s[i/4*4+1]){
                f=false;
                break;
            }
        }
    }
    if(f){
        cout<<"abba";
        return;
    }

    f=true;
    for(int i=0;i<4*n;++i){
        if(i%4 == 0 || i%4==1) {
            if(s[i]!=s[i/4*4+0]){
                f=false;
                break;
            }
        }
        else {
            if(s[i]!=s[i/4*4+2]){
                f=false;
                break;
            }
        }
    }
    if(f){
        cout<<"aabb";
        return;
    }


    cout<<"NO";
}