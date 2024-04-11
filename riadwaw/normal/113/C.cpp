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

//bool prime [150000020];
vector<bool> prime(150000020,false);
void solve(){
    int l,r;
    cin>>l>>r;
        for (int i=3; i<=17321; i+=2)
        if (!prime[i>>1])
            for (int j=i+i; j<=300000000; j+=i)
                if(j&1)
                    prime[j>>1] = true;
        int c=0;
        if(l==1)
            l=2;
        for(int i=l;i<=r;){
            if(i==2){
                ++c;
                i=5;
                continue;
            }
            if((i&3)==1){
                if(!prime[i>>1])
                    ++c;
                i+=4;
            }
            else
                ++i;
        }
        cout<<c;
}