#include <iostream>
#include <set>
using namespace std;
const int N=200000+10;
set<int> st[3]; int bit[3][N];
void add(int type,int pos,int val){
    while(pos<N){
        bit[type][pos]+=val; pos+=pos&-pos;
    }
}
int sum(int type,int pos){
    int ans=0;
    while(pos>0){
        ans+=bit[type][pos]; pos-=pos&-pos;
    } return ans;
}
int n,q; char s[N];
int id(char ch){
    return ch=='R'?0:(ch=='P'?1:2);
}
int query(){
    int ans=0;
    for(int i=0;i<3;i++){
        int nex=(i+2)%3;
        if(st[nex].size()==0){
            if(st[i].size()==n) ans += n;
            continue;
        }
        int str = *st[nex].begin();  // [1,str)
        int ed = *st[nex].rbegin(); // (ed,n]
        ans += sum(i,ed) - sum(i,str);
        int j = (i+1)%3;
        if(st[j].size()==0) {
            ans += str-1 + n-ed; continue;
        }
        int p1 = *st[j].begin(); ans += min(str-1, p1-1);
        int p2 = *st[j].rbegin(); ans += min(n-ed, n-p2);
    } 
    printf("%d\n", ans);
    return ans;
}
int main() {
    scanf("%d%d%s",&n,&q,s+1);
    for(int i=1;i<=n;i++){
        add(id(s[i]),i,+1);
        st[id(s[i])].insert(i);
    }
    query();
    for(int i=1;i<=q;i++){
        int p; char str[2]; scanf("%d%s",&p,str); char ch=str[0];
        add(id(s[p]),p,-1); st[id(s[p])].erase(p);
        s[p]=ch;
        add(id(s[p]),p,+1); st[id(s[p])].insert(p);
        query();
        //printf("%s\n", s+1);
    }
}