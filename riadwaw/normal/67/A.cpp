#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<char, char> pi;
typedef pair<li, li> pli;
#define mp make_pair
void solve();

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a[1111];
    a[0]=1;
    for(int i=0;i<n-1;++i){
        if(s[i]=='R')
            a[i+1]=a[i]+1;
        else if(s[i]=='=')
            a[i+1]=a[i];
        else{
            a[i+1]=1;
            for(int j=i;j>=0;--j){
                if(s[j]=='R')
                    break;
                if(s[j]=='L')
                    if(a[j]<=a[j+1])
                        a[j]=a[j+1]+1;
                    else
                        break;
                else if(s[j]=='=')
                    if(a[j]!=a[j+1])
                        a[j]=a[j+1];
                    else
                        break;
            }
        }
    }
    for(int i=0;i<n;++i)
        cout<<a[i]<<' ';
}