#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int v[7]={0,4,8,15,16,23,42},ans[10];
vector<int> tmp;

set<int> ask(int x,int y){
    printf("? %d %d\n", x,y);
    fflush(stdout);
    int a; scanf("%d",&a);
    tmp.push_back(a);
    set<int> st;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(a==v[i]*v[j]){
                st.insert(v[i]);
                st.insert(v[j]);

                return st;
            }
        }
    }
}

int main() {
    set<int> s1,s2;
    s1 = ask(1,2);
    s2 = ask(2,3);
    for(auto x: s1) {
        if (s2.count(x)) {
            ans[2]=x; break;
        }
    }
    ans[1] = tmp[0] / ans[2];
    ans[3] = tmp[1] / ans[2];

    s1 = ask(4,5);
    s2 = ask(5,6);
    for(auto x: s1) {
        if (s2.count(x)) {
            ans[5]=x; break;
        }
    }
    ans[4] = tmp[2] / ans[5];
    ans[6] = tmp[3] / ans[5];    
    printf("!");
    for(int i=1;i<=6;i++){
        printf(" %d", ans[i]);
    }
    printf("\n");
    fflush(stdout);
}