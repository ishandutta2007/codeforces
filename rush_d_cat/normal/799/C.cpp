#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100000 + 10;
int n,c,d;
vector< pair<int,int> > v[2];

int bit[N];
void add(int pos,int x){
    //printf("add %d %d\n", pos,x);
    while(pos<N){
        bit[pos]=max(bit[pos],x); pos += pos&-pos;
    }
}
int query(int pos){
    int ans=0;
    //printf("que %d\n", pos);
    while(pos>0){
        ans=max(ans,bit[pos]); pos -= pos&-pos;
    } return ans;
}
int main() {
    scanf("%d%d%d",&n,&c,&d);
    int mx1=0,mx2=0;
    for(int i=1;i<=n;i++){
        int b,p; char s[2]; scanf("%d%d%s",&b,&p,s);
        if(s[0]=='C') {
            v[0].push_back(make_pair(p,b));
            if(p<=c)mx1=max(mx1,b);
        }
        if(s[0]=='D') {
            v[1].push_back(make_pair(p,b));
            if(p<=d)mx2=max(mx2,b);
        }
    }

    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    // CC
    int ans=0;
    if(mx1&&mx2) ans=mx1+mx2;

    for(int l=0;l<v[0].size();l++) {
        int tmp=query(c-v[0][l].first);
        if(tmp>0)ans=max(ans,tmp+v[0][l].second);
        add(v[0][l].first,v[0][l].second);
    }
    //printf("ok\n");
    // DD
    memset(bit,0,sizeof(bit));
    for(int l=0;l<v[1].size();l++) {
        int tmp=query(d-v[1][l].first);
        if(tmp>0)ans=max(ans,tmp+v[1][l].second);
        add(v[1][l].first,v[1][l].second);
    }
    cout<<ans<<endl;

}