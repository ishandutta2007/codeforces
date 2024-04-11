#include <iostream>
#include <vector>
using namespace std;
char s[102],t[102];int n;
int main() {
    scanf("%d%s%s",&n,s+1,t+1);
    vector<int> ans;

    for(int i=1;i<=n;i++) {
        int pos=-1;
        for(int j=i;j<=n;j++) {
            if(s[j]==t[i]) {
                pos = j; break;
            }
        }   
        //printf("%s %s\n", s+1, t+1);
        //printf("pos = %d\n", pos);
        for(int j=pos-1;j>=i;j--) {
            swap(s[j],s[j+1]);
            ans.push_back(j);
        }
        if(pos==-1) {
            return !printf("-1\n");
        }
    }
    printf("%d\n", ans.size());
    for(auto x:ans) printf("%d ",x);
}