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
    int x,y;
    cin>>x>>y;
    while(true){
        if(x>=2 && y>=2){
            x-=2;
            y-=2;
        }
        else if(x>=1 && y>=12){
            x-=1;
            y-=12;
        }
        else if(y>=22){
            y-=22;
        }
        else{
            cout<<"Hanako";
            return;
        }
        if(y>=22){
            y-=22;
        }       
        else if(x>=1 && y>=12){
            x-=1;
            y-=12;
        }
        else if(x>=2 && y>=2){
            x-=2;
            y-=2;
        }
        else{
            cout<<"Ciel";
            return;
        }
    }
}