#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;
typedef long long li;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<li, li> pli;
typedef double ld;
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
    char f1,f2,t1,t2;
    cin>>f1>>f2>>t1>>t2;
    cout<<max(abs(f2-t2),abs(f1-t1))<<endl;
    while(f1!=t1 || f2!=t2){
        if(f1>t1){
            cout<<"L";
            f1--;
        }
        else if(f1<t1){
            cout<<"R";
            f1++;
        }
        if(f2>t2){
            cout<<"D";
            f2--;
        }
        else if(f2<t2){
            cout<<"U";
            f2++;
        }
        cout<<endl;
    }
}