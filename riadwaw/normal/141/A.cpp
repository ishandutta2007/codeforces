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
#define mp make_pair

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

int c[1000];
void solve() {
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    for(int i=0;i<s1.length();++i){
        c[s1[i]]++;
    }
for(int i=0;i<s2.length();++i){
        c[s2[i]]++;
    }
    for(int i=0;i<s3.length();++i){
        c[s3[i]]--;
    }

    for(char z='A';z<='Z';++z){
        if(c[z]){
            cout<<"NO";
            return;
        }
    }
    cout<<"YES";
}