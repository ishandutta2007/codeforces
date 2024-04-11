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
/**
 CAUTION Is int really int?
 * 
 Real solution after main function
 */
//#define int li
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef double ld;

fknmain main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
#define LL "%lld"
#else
#define LL "%I64d"
#endif
#ifndef int
#define INT "%d"
#else
#define INT LL
#endif
    solve();
    return 0;
}
#define get(n) s.length()-n
int type(string &s){
    //     -lios,     -liala.
//     -etr,     -etra.
//     -initis,     -inites.
    if(s.length()>=4 && s[get(1)]=='s' && s[get(2)]=='o' && s[get(3)]=='i' && s[get(4)]=='l')
        return 1;
    if(s.length()>=5 && s[get(1)]=='a' && s[get(2)]=='l' && s[get(3)]=='a' && s[get(4)]=='i' && s[get(5)]=='l')
        return 2;
    if(s.length()>=3 && s[get(1)]=='r' && s[get(2)]=='t' && s[get(3)]=='e')
        return 3;
    if(s.length()>=4 && s[get(1)]=='a' && s[get(2)]=='r' && s[get(3)]=='t' && s[get(4)]=='e')
        return 4;
    if(s.length()>=6 && s[get(1)]=='s' && s[get(2)]=='i' && s[get(3)]=='t' && s[get(4)]=='i' && s[get(5)]=='n' && s[get(6)]=='i')
        return 5;
    if(s.length()>=6 && s[get(1)]=='s' && s[get(2)]=='e' && s[get(3)]=='t' && s[get(4)]=='i' && s[get(5)]=='n' && s[get(6)]=='i')
        return 6;
    return 0;
}
void solve(){
    string v[101010];
    int tp[101010];
    int n=0;
    int flag=0;
    bool bad=false;
    while(cin>>v[n]){

        tp[n]=type(v[n]);
        if(!tp[n] || ((tp[n]%2) != (tp[0]%2)) || tp[n]<flag){
            cout<<"NO";
            //cout<<n<<tp[n];
            return;
        }
        if(tp[n]==flag &&  (tp[n]==3 || tp[n]==4) ){
            cout<<"NO";
            return;
        }
        if(tp[n]>4 && flag<3)
            bad=true;
        flag=tp[n];
        ++n;
    }
    if(flag<3 && n>1){
        cout<<"NO";
        return;
    }
    if(bad && n>1){
        cout<<"NO";
        return;
    }
    cout<<"YES";
}