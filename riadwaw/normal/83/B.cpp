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
#define int li
void solve(){
    int n,t[101010];
    pi a[101010];
    li k,s=0;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        scanf("%d",&a[i].first);
        t[i]=a[i].first;
        a[i].second=i;
        s+=a[i].first;
    }
    if(s<k){
        cout<<-1;
        return ;
    }
    sort(a,a+n);
    vi first,second;
    int r=0;
    for(int i=0;i<n;++i){
        if((n-i)*(a[i].first-r)<=k){            
            k-=((n-i)*(a[i].first-r));
            r=a[i].first;
        }
        else{
            int c=k/(n-i);
            r+=c;
            k-=(n-i)*c;
            for(int j=0;j<n;++j){
                if(t[j]>r){
                    if(k){
                        --k;
                        if(t[j]>r+1)
                            first.pb(j);
                    }
                    else{
                        second.pb(j);
                    }
                }
            }
            break;
        }
    }
    for(int i=0;i<second.size();++i){
        printf("%d ",(second[i]+1));
    }
    for(int i=0;i<first.size();++i){
        printf("%d ",(first[i]+1));
    }
}