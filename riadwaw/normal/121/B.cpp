#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;
void solve();

#define mp make_pair
#define pb push_back

typedef long long li;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main() {
#ifdef DEBUG
    freopen("input", "r", stdin);
    //freopen("output","w",stdout);
#else
#endif
    //cin.sync_with_stdio(false);
    //cout.sync_with_stdio(false);
    solve();
    return 0;
}
template <typename T>
bool lucky(T n){
    while(n){
        if((n%10)!=4 && (n%10) !=7){
            return false;
        }
        n/=10;
    }
    return true;
}
void solve(){
    int n,k;
    char s[101010];
    scanf("%d %d %s",&n,&k,s);
    int last=-1;
    for(int i=0;i<n-1;++i){
        if(i<0)i=0;
        if(k<1)
            break;
        if(s[i]=='4' && s[i+1]=='7'){
            if((i%2)==0){
                s[i+1]='4';
                --k;
                if(last==i+1){
                    k=k%2;
                }
                else
                    last=i+1;
                i-=3;
            }
            else{
                s[i]='7';
                --k;
                if(last==i){
                    k=k%2;
                }
                else
                    last=i;
                i-=3;
            }
        }
    }

    printf("%s",s);
}