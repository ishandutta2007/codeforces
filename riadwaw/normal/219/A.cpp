#include <iostream>
#include <string>
using namespace std;
int cnt[256];
int main(){
    string s;
    
    int k;
    cin>>k;
    cin>>s;
    int n = s.length();

for(int i =0; i < n;++i){
    cnt[s[i]] ++;
}

for(int i = 0; i < 256; ++i){
    if(cnt[i]%k){
        cout<<-1;
        return 0;
    }
}
for(int j =0 ; j < k;++j){
for(int i =0; i < 256;++i){
    for(int l = 0; l < cnt[i]/k; ++l){
        cout<<(char)i;
    }
}
}
    return 0;
}