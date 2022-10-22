#include<set>
#include<cstdio>
#include<vector>

using namespace std;

int n;
int a[100000];

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    set<int> ret, s1, s2;
    for(int i = 0; i < n; i++){
        for(set<int>::iterator it = s1.begin(); it != s1.end(); it++){
            int y = (*it) | a[i];
            ret.insert(y);
            s2.insert(y);
        }
        ret.insert(a[i]);
        s2.insert(a[i]);
        s1 = s2;
        s2.clear();
    }
    printf("%d\n", (int)ret.size());
    return 0;
}