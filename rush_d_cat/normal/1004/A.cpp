#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
LL n,d,x[102];
LL Abs(LL x){
    if(x<0) return -x;
    return x;
}
bool chk(LL pos){
    LL mn=1e18;
    for(int i=1;i<=n;i++){
        mn=min(mn,Abs(x[i]-pos));
    }
    return mn==d?1:0;
}
set<LL> st;
int main() {
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        cin>>x[i];
    for(int i=1;i<=n;i++) {
        if(chk(x[i]-d))
            st.insert(x[i]-d);
        if(chk(x[i]+d))
            st.insert(x[i]+d);
    }
    cout<<st.size()<<endl;
}