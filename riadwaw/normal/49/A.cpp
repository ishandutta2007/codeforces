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
typedef pair<int, int> pi;
typedef long long int li;
typedef vector<int> vi;
typedef double ld;
void solve();
#define mp make_pair
#define pb push_back

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#endif
    solve();
    return 0;
}
void solve(){
    string s;
    getline(cin,s);
    int i=s.length()-1;
    while(!((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')))
        --i;
    cout<<((s[i]=='a' || s[i]=='A' || s[i]=='o'|| s[i]=='O' || s[i]=='Y' || s[i]=='y' || s[i]=='i' || s[i]=='I' || s[i]=='e' || s[i]=='e' || s[i]=='u' || s[i]=='U')?"YES":"NO");
}