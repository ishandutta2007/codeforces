#include <iostream>
#include <string>
using namespace std;
int cnt[256];
typedef long long li;
void solve();
int main(){

solve();
return 0;
}


void solve(){
    li s, m;
    cin>>s>>m;

    li cur = 1000000000000000000;
    
    while(cur){
        li mod = s % cur;
        li need = (mod + 1) % cur;


        if(need <= m){
            cout<<s - need;
            return;
        }

        cur/=10;
    }
}