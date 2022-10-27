#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
using namespace std;
const int N = 200000+10;
char s[N];
int main() {
    scanf("%s",s+1); int n=strlen(s+1);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]!='a')cnt++;
    }
    if(cnt%2) return !printf(":(\n");
    int now=0,pos=n+1;
    for(int i=n;i>=1;i--){
        if(now*2>=cnt) break;
        if(s[i]!='a'){
            now++;
            if(now*2==cnt){
                pos=i; break;
            }
        } else {
            return !printf(":(\n");
        }
    }
    // [pos,n]
    // [1,pos-1]
    vector<char> v1,v2;
    for(int i=1;i<=pos-1;i++){
        if(s[i]!='a')v1.push_back(s[i]);
    }
    for(int i=pos;i<=n;i++){
        if(s[i]!='a')v2.push_back(s[i]);
    }
    if(v1!=v2){
        return !printf(":(\n");
    }
    for(int i=1;i<pos;i++)printf("%c", s[i]);
    printf("\n");
}