#include <iostream>
#include <vector>
using namespace std;
char s[3][3],t[3][3];
vector<char> vs, vt;
int main() {
    scanf("%s%s%s%s",s[0],s[1],t[0],t[1]);
    if(s[0][0]!='X') vs.push_back(s[0][0]);
    if(s[0][1]!='X') vs.push_back(s[0][1]);
    if(s[1][1]!='X') vs.push_back(s[1][1]);
    if(s[1][0]!='X') vs.push_back(s[1][0]);

    if(t[0][0]!='X') vt.push_back(t[0][0]);
    if(t[0][1]!='X') vt.push_back(t[0][1]);
    if(t[1][1]!='X') vt.push_back(t[1][1]);
    if(t[1][0]!='X') vt.push_back(t[1][0]);

    for(int i=0;i<3;i++) vs.push_back(vs[i]);
    for(int i=0;i<3;i++){
        if(vs[i]==vt[0]) {
            //printf("i=%d\n", i);
            bool ok=1;
            for(int j=0;j<3;j++){
                if(vs[i+j] != vt[j]) {
                    ok=0;
                }
            }
            printf("%s\n", ok?"YES":"NO"); 
            return 0;
        }
    }

}