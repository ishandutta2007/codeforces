#include <set>
#include <map>
#include <string>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>
using namespace std;
typedef pair<int,int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    solve();
    return 0;
}
int g;
int kmp(string &find,const char*text){
    char s[201010];
    int pi[201010];
    int l1=find.length(),l2=strlen(text);
    memcpy(s,find.c_str(),l1);
    s[l1]=0;
    memcpy(s+l1+1,text,l2);
    int n=l1+l2+1;
    s[n]=0;
    pi[0]=0;
    for(int i=1;i<n;++i){
        int j=pi[i-1];
        while(j>0 && s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            ++j;
        if(j==l1){
            g=i-l1;
            return true;
        }
        pi[i]=j;
    }
    return false;
}

int f(string &real,string &a,string &b){
    return kmp(a,real.data()) && kmp(b,real.data()+g);
}
void solve(){
    string real,a,b;
    cin>>real>>a>>b;
    int res=f(real,a,b);
    reverse(real.begin(),real.end());
    res+=f(real,a,b)<<1;
    cout<<(res==3?"both":res==2?"backward":res==1?"forward":"fantasy");
}