#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
const int N=100+10;
int f(char c){
    if(c=='R')return 5;
    if(c=='G')return 6;
    if(c=='B')return 7;
    if(c=='Y')return 8;
    if(c=='W')return 9;
}
int g(char c){
    return c-'1';
}
struct Card{
    int a,b,state;
    void read(){
        char s[3]; scanf("%s",s);
        a=f(s[0]), b=g(s[1]); state=0;
    }
} card[N];
int n;
int count(int x){
    int res=0;
    while(x){
        if(x&1)res++; x>>=1;
    } return res;
}

int solve(int mask){
    set<int> cd;
    for(int i=1;i<=n;i++)card[i].state=0;
    for(int i=1;i<=n;i++){
        cd.insert((1<<card[i].a)|(1<<card[i].b));
    }
    //printf("sz = %d\n", cd.size());
    for(int i=0;i<10;i++){
        if(mask>>i&1) {
            for(int x=1;x<=n;x++){
                if(card[x].a == i) card[x].state |= 1<<i;
                if(card[x].b == i) card[x].state |= 1<<i;
            }
        }
    }
    set<int> st;
    for(int i=1;i<=n;i++) st.insert(card[i].state);
    if(st.size() == cd.size()) {
        return count(mask);
    }
    return 12;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)card[i].read();
    int ans=12; 
    for(int mask=0;mask<1<<10;mask++) {
        ans=min(ans,solve(mask));
    }
    cout<<ans<<endl;
}