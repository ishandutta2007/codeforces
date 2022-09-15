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
using namespace std;
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
void solve(){
    int n,m;
    cin>>n>>m;
    string s[55];
    for(int i=0;i<n;++i){
        cin>>s[i];
    }
    int sf=0,se=n,tf=0,te=m;
    while(true){
        bool f=true;
        for(int j=0;j<m;++j){
            if(s[sf][j]=='*'){
                //cout<<"xx"<<s[sf][j]<<' '<<sf<<' '<<j<<"xx"<<endl;
                f=false;
                break;
            }
        }
        if(f)
            sf++;
        else
            break;
    }
    while(true){
        bool f=true;
        for(int j=0;j<m;++j){
            if(s[se-1][j]=='*'){
                f=false;
                break;
            }
        }
        if(f)
            se--;
        else
            break;
    }
    while(true){
        bool f=true;
        for(int j=0;j<n;++j){
            if(s[j][tf]=='*'){
                f=false;
                break;
            }
        }
        if(f)
            tf++;
        else
            break;
    }
    while(true){
        bool f=true;
        for(int j=0;j<n;++j){
            if(s[j][te-1]=='*'){
                f=false;
                break;
            }
        }
        if(f)
            te--;
        else
            break;
    }
    for(int i=sf;i<se;++i){
        for(int j=tf;j<te;++j){
            cout<<s[i][j];
        }
        cout<<endl;
    }
}