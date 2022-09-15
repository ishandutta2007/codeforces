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

void solve();
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

fknmain main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
    #define INT "%lld"
#else
    #define INT "%I64d"
#endif
#ifndef int
    #undef INT
    #define INT "%d"
#endif
    solve();
    return 0;
}
struct tp{
    int cnt;
    string word;
    tp(string a){
        cnt=0;
        for(int i=0;i<a.size();++i){
            if(a[i]=='&')
                --cnt;
            else if(a[i]=='*')
                ++cnt;
            else
                word+=a[i];
        }
    }
};
void solve(){
    map<string,int> a;
    a[string("void")]=0;
    int n;
    cin>>n;
    string s,type,nw;
    for(int i=0;i<n;++i){
        cin>>s>>type;
        tp TYPE(type);
        if(s[4]=='d'){
            cin>>nw;
            if(a.find(TYPE.word)==a.end() || a[TYPE.word]+TYPE.cnt<0)
                a.erase(nw);
            else
                a[nw]=a[TYPE.word]+TYPE.cnt;
        }
        else{           
            if(a.find(TYPE.word)==a.end() || a[TYPE.word]+TYPE.cnt<0)
                cout<<"errtype\n";
            else{
                int cnt=a[TYPE.word]+TYPE.cnt;
                cout<<"void";
                for(int i=0;i<cnt;++i)
                    cout<<"*";
                cout<<'\n';
            }
        }
    }
}