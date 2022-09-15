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
int k;
map<int,bool> mapa;
bool f(int n,int m){
    //cout<<n<<' '<<m<<' ';
    if(n%2==0)
        return false;
    map<int,bool>::iterator it=mapa.find(m);
    if(it!=mapa.find(m))
        return it->second;
    for(int i=1;i*i<=m;++i){
        if(m%i==0){
            if(i>=k && i<m){
                if(!f(m/i,i)){
                    mapa[m]=true;
                    return true;
                }
            }
            if(m/i>=k && i!=1){
                if(!f(i,m/i)){
                    mapa[m]=true;
                    return true;
                }
            }
        }
    }
    mapa[m]=false;
    return false;
}

void solve(){
    int n,m;
    cin>>n>>m>>k;
    if(f(n,m))
        cout<<"Timur";
    else
        cout<<"Marsel";
}