#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <math.h>
#include <sstream>
#include <complex>
#include <string.h>
#include <algorithm>
using namespace std;

void solve();
#define mp make_pair
#define pb push_back
typedef int fknmain;
typedef long long int li;
#define int li
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
enum s{Widget, VBox, HBox};
struct elem{
    int w,h,bor,space;
    vector<string> child;
    s type;
    elem(s a){
        w=0;
        h=0;
        bor=0;
        space=0;
        type=a;
    }
    elem(){}
    elem(int W,int H){
        type=Widget;
        w=W;
        h=H;
        bor=0;
        space=0;
    }
};
typedef map<string,elem>::iterator iter;
map<string,elem> m;
map<string,bool> used;
void cnt(iter it){
    if(it->second.type==Widget ||  used[it->first])
        return;
    used[it->first]=true;
    if(!it->second.child.size())
        return;
    for(int i=0;i<it->second.child.size();++i){
        cnt(m.find(it->second.child[i]));
        if(it->second.type==HBox){
            it->second.w+=m[it->second.child[i]].w;
            it->second.h=max(m[it->second.child[i]].h,it->second.h);
            //cout<<it->first<<' '<<it->second.w<<' '<<it->second.h<<endl;
        }
        else{
            it->second.h+=m[it->second.child[i]].h;
            it->second.w=max(m[it->second.child[i]].w,it->second.w);
        }
    }
    it->second.w+=2*it->second.bor;
    it->second.h+=2*it->second.bor;
    if(it->second.type==HBox){
        it->second.w+=(it->second.child.size()-1)*it->second.space;
    }
    else{
        it->second.h+=(it->second.child.size()-1)*it->second.space;
    }
    
}
void solve(){
    int n;
    cin>>n;
    string s;
    getchar();
    for(int i=0;i<n;++i){
        getline(cin,s);
        if(s[0]=='W' && s[1]=='i' && s[2]=='d' && s[3]=='g' && s[4]=='e' && s[5]=='t' && s[6]==' '){
            int j;
            string name;
            for(j=7;s[j]!='(';++j){
                name+=s[j];
            }
            int w,h;
            sscanf(s.data()+j,"("INT","INT")",&w,&h);
            m[name]=elem(w,h);
        }
        else if(s[0]=='V' && s[1]=='B' && s[2]=='o' && s[3]=='x' && s[4]==' '){
            m[string(s.data()+5)]=elem(VBox);
        }
        else if(s[0]=='H' && s[1]=='B' && s[2]=='o' && s[3]=='x' && s[4]==' '){
            m[string(s.data()+5)]=elem(HBox);
        }
        else{
            int j=0;
            while(s[j]!='.')
                ++j;
            string name = s.substr(0,j);
            string command;
            ++j;
            while(s[j]!='('){
                command+=s[j];
                ++j;
            }
            //cout<<command;
            if(command==string("pack")){
                ++j;
                string child;
                while(s[j]!=')'){
                    child+=s[j];
                    ++j;
                }
                m[name].child.push_back(child);
            }
            else if(command==string("set_border")){
                int k;
                sscanf(s.data()+j,"("INT")",&k);
                m[name].bor=k;
            }
            else{
                int k;
                sscanf(s.data()+j,"("INT")",&k);
                m[name].space=k;
            }
        }
    }
    
    //cout<<m["father"].child[0];
    for(iter it=m.begin();it!=m.end();++it){
        cnt(it);
    }
    for(iter it=m.begin();it!=m.end();++it){
        cout<<it->first<<' '<<it->second.w<<' '<<it->second.h<<endl;
    }
}