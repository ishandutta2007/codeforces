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

int main(){
#ifdef DEBUG
    freopen("input", "r", stdin);
#endif
    solve();
    return 0;
}
#define int li
int tree[1<<19],shift=1<<18,moded[1<<19];
int added(int a){
    if(a)
        return moded[a]+added(a/2);
    return 0;
}
int rmq(int l,int r){
    if(l>r)
        return 1LL<<60;
    if(l%2)
        return min(tree[l]+added(l),rmq(l+1,r));
    if(r%2==0){
        return min(tree[r]+added(r),rmq(l,r-1));
    }
    return rmq(l/2,r/2);
}
void rebuild(int x){
    if(x){
        tree[x]=min(tree[x*2]+moded[x*2],tree[x*2+1]+moded[x*2+1]);
        rebuild(x/2);
    }
}
void add(int l,int r,int k){
    if(l>r)
        return;
    if(l%2){
        moded[l]+=k;
        rebuild(l/2);
        add(l+1,r,k);
        return;
    }
    if(r%2==0){
        moded[r]+=k;
        rebuild(r/2);
        add(l,r-1,k);
        return;
    }
    add(l/2,r/2,k);
}
void solve(){
    int n,l,r,inc,m;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>tree[shift+i];
    }
    for(int i=shift-1;i;--i){
        tree[i]=min(tree[2*i],tree[2*i+1]);
    }
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>l>>r;
        if(getchar()==' '){
            cin>>inc;
            if(l<=r)
                add(l+shift,r+shift,inc);
            else{
                add(l+shift,n-1+shift,inc);
                add(shift,shift+r,inc);
            }
        }
        else{
            if(l<=r)
                cout<<rmq(l+shift,r+shift)<<endl;
            else{
                cout<<min(
                        rmq(l+shift,n-1+shift),
                        rmq(shift,shift+r)
                        )<<endl;
            }
        }
    }
}