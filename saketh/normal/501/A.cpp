#include <cstdio>
#include <algorithm>
using namespace std;
int a, b, c, d, m, v;
int main(){
    scanf("%d%d%d%d", &a, &b, &c, &d);
    m = max(3*a/10, a-a*c/250);
    v = max(3*b/10, b-b*d/250);
    printf("%s\n", m==v ? "Tie" : m>v ? "Misha" : "Vasya");
}