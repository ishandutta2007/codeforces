#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n,k; char s[N];
set<int> st[2];
bool flag=0;
bool gg(){
    return st[0].size()==0 || st[1].size()==0;
}
bool ok(){
    for(int x=0;x<2;x++)
        if((int)st[x].size()==0 || (*st[x].rbegin())-(*st[x].begin())+1<=k ) return 1;
    return 0;
}
void cac(int x){
    st[0].clear(); st[1].clear();
    for(int i=1;i<=n;i++){
        st[s[i]-'0'].insert(i);
    }
    for(int i=1;i<=k;i++){
        st[s[i]-'0'].erase(i);
        st[x].insert(i);
    }
    if(gg()){
        printf("tokitsukaze\n"); exit(0);
    }
    if(!ok()) flag=1;
    for(int i=k+1;i<=n;i++){
        st[s[i]-'0'].erase(i); 
        st[x].insert(i);
        st[x].erase(i-k);
        st[s[i-k]-'0'].insert(i-k);

        if(gg()){
            printf("tokitsukaze\n"); exit(0);
        }
        if(!ok()) flag=1;
    }
}
int main() {
    scanf("%d%d%s",&n,&k,s+1);
    cac(0);  
    cac(1);
    printf("%s\n", flag?"once again":"quailty");
}