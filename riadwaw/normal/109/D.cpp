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
    freopen("output","w",stdout);
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
bool have = false;
bool is_good(int n){
    while(n){
        int o=n%10;
        if(o!=7 && o!=4)
            return false;
        n/=10;
    }
    have=true;
    return true;
}
void solve() {
    int n,a[101010];
    int where[101010];
    int what[101010];
    pi b[101010];
    int good=0;
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%d",&b[i].first);
        a[i]=b[i].first;
        b[i].second=i;
        if(is_good(a[i]))
            good=i;
        where[i]=i;
        what[i]=i;
    }
    vector<pi> ans;
    if(have){
        sort(b,b+n);
        for(int i=0;i<n;++i){
            
            
            ans.pb(pi(i,good));
            where[what[i]]=good;
            where[what[good]]=i;
            swap(what[i],what[good]);
            good=where[b[i].second];
          ans.pb(pi(i,good));
            where[what[i]]=good;
            where[what[good]]=i;
            swap(what[i],what[good]);
            
            
        }
        int c=0;
        for(int i=0;i<int(ans.size());++i){
            if(ans[i].first!=ans[i].second)
                ++c;
        }
        cout<<c<<endl;
        for(int i=0;i<int(ans.size());++i){
            if(ans[i].first!=ans[i].second)
                printf("%d %d\n",ans[i].first+1,ans[i].second+1);
        }
        
        //for(int i=0;i<(int)ans.size();++i)
        //  swap(a[ans[i].first],a[ans[i].second]);
        
        //for(int i=0;i<n;++i)
        //  cout<<a[i]<<' ';
    }
    else{
        sort(b,b+n);
        for(int i=0;i<n;++i){
            if(a[i]!=b[i].first){
                cout<<-1;
                return;
            }
        }
        cout<<0;
    }
}