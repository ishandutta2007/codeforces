#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
char s[100000+10];
int ok = 1;
vector<int> v;
int main() {
    scanf("%s", s+1);
    int n = strlen(s+1);
    
    int cnt = 0;
    int last = -1;

    int need = 0;

    for(int i=1;i<=n;i++) {
        if(s[i] == '(') {
            need ++;
        } else {
            need --;
        }
    }

    need ++;

    if(need <= 0) {
        ok = 0;
    }

    for(int i=n;i>=1;i--) {
        if(s[i] == '#') {
            last = i;
            break;
        }
    }


    for(int i=1;i<=n;i++) 
    {
        if(s[i] == '(') {
            cnt ++;
        }
        if(s[i] == ')') {
            cnt --;
        }

        if(s[i] == '#') {
            if(i == last) {
                v.push_back(need);
                cnt -= need;
            } else {
                cnt --; v.push_back(1);
            }
        }

        if(cnt < 0) ok = 0;
    }

    if(ok == 0) return 0*printf("-1\n");

    for(int i=0;i<v.size();i++) {
        printf("%d\n", v[i]);
    }

}