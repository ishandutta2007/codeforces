#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
void solve();
int main(){
#ifdef DEBUG
    freopen("input","r",stdin);
#endif
    solve();
    return 0;
}

void solve(){
    int n;
    int ar[5]={0,0,0,0,0};
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        ar[a]++;
    }
    cout<<min(min(ar[1]+ar[2],ar[2]+ar[3]),ar[1]+ar[3]);
}