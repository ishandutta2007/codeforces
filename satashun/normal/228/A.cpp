#include <cstdio>
#include <set>
using namespace std;

int a, b, c, d;
set<int> hoge;
int main(){
    scanf("%d %d %d %d", &a, &b, &c, &d);
    hoge.insert(a);
    hoge.insert(b);
    hoge.insert(c);
    hoge.insert(d);
    printf("%d\n", 4 - hoge.size());
    return 0;
}