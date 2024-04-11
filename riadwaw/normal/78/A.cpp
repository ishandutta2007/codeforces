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
void solve(){
    char buf[122];
    for(int i=0;i<3;++i){
        cin.getline(buf,110);
        int n=strlen(buf),c=0;
        for(int j=0;j<n;++j){
            if(buf[j]=='a' || buf[j]=='u'|| buf[j]=='i'|| buf[j]=='o' || buf[j]=='e')
                ++c;
        }
        //cout<<c;
        if((c-(i%2)*2)!=5){
            cout<<"NO";
            return ;
        }
    }
    cout<<"YES";
}